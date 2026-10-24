"""
Utility functions for rate limiting, retries, and error handling.
"""

import time
import urllib.error
from typing import Callable, TypeVar, Optional
from functools import wraps

T = TypeVar('T')


def rate_limit_delay(seconds: float = 2.0):
    """
    Enforce a delay between API calls to respect rate limits.

    Args:
        seconds: Minimum seconds to wait between calls
    """
    time.sleep(seconds)


def retry_with_backoff(
    max_retries: int = 3,
    initial_delay: float = 1.0,
    backoff_factor: float = 2.0,
    retryable_errors: tuple = (urllib.error.URLError, urllib.error.HTTPError, TimeoutError, ConnectionError),
) -> Callable:
    """
    Decorator to retry a function with exponential backoff on transient errors.

    Args:
        max_retries: Maximum number of retry attempts
        initial_delay: Initial delay in seconds before first retry
        backoff_factor: Multiplier for delay after each retry
        retryable_errors: Tuple of exception types that should trigger a retry
    """
    def decorator(func: Callable[..., T]) -> Callable[..., T]:
        @wraps(func)
        def wrapper(*args, **kwargs) -> T:
            last_exception = None
            delay = initial_delay

            for attempt in range(max_retries + 1):
                try:
                    return func(*args, **kwargs)
                except retryable_errors as e:
                    last_exception = e
                    if attempt < max_retries:
                        # Exponential backoff
                        time.sleep(delay)
                        delay *= backoff_factor
                    else:
                        # Final attempt failed, raise the exception
                        raise
                except Exception as e:
                    # Non-retryable error, raise immediately
                    raise

            # This should never be reached, but just in case
            if last_exception:
                raise last_exception
            raise RuntimeError("Retry logic failed unexpectedly")

        return wrapper
    return decorator
