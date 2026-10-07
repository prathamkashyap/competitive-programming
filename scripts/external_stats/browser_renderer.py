"""
Browser-rendered profile retrieval using Playwright.

This module provides browser automation for extracting data from client-rendered
competitive programming profile pages.
"""

import json
import re
import asyncio
from typing import Dict, Any, Optional, List
from datetime import datetime


def is_playwright_available() -> bool:
    """Check if Playwright is available."""
    try:
        import playwright
        return True
    except ImportError:
        return False


async def fetch_rendered_page(
    url: str,
    wait_selector: Optional[str] = None,
    wait_timeout: int = 10000,
    capture_network: bool = False,
) -> Dict[str, Any]:
    """
    Fetch a page with browser rendering and extract its content.

    Args:
        url: The URL to fetch
        wait_selector: CSS selector to wait for before extracting content
        wait_timeout: Maximum time to wait for the selector (ms)
        capture_network: Whether to capture network requests

    Returns:
        Dict containing:
        - html: Rendered HTML
        - text: All visible text
        - scripts: Embedded script contents
        - json_data: Any JSON data found in scripts
        - network_requests: List of network requests (if capture_network=True)
    """
    from playwright.async_api import async_playwright

    result = {
        "html": "",
        "text": "",
        "scripts": [],
        "json_data": {},
        "network_requests": [],
    }

    async with async_playwright() as p:
        browser = await p.chromium.launch(headless=True)
        try:
            context = await browser.new_context(
                user_agent='Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36',
                viewport={'width': 1920, 'height': 1080},
            )
            page = await context.new_page()

            # Capture network requests if requested
            if capture_network:
                requests = []

                async def handle_request(request):
                    requests.append({
                        "url": request.url,
                        "method": request.method,
                        "resource_type": request.resource_type,
                    })

                page.on("request", handle_request)

                async def handle_response(response):
                    try:
                        content_type = response.headers.get("content-type", "")
                        if "application/json" in content_type or "application/graphql" in content_type:
                            try:
                                body = await response.body()
                                if body:
                                    for req in requests:
                                        if req["url"] == response.url:
                                            req["response_body"] = body.decode('utf-8', errors='ignore')
                                            req["status"] = response.status
                                            break
                            except Exception:
                                pass
                    except Exception:
                        pass

                page.on("response", handle_response)

            # Navigate to the URL with domcontentloaded as fallback
            # Add realistic headers to avoid 403 errors
            await page.set_extra_http_headers({
                'Accept-Language': 'en-US,en;q=0.9',
                'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,*/*;q=0.8',
                'Accept-Encoding': 'gzip, deflate, br',
                'DNT': '1',
                'Connection': 'keep-alive',
                'Upgrade-Insecure-Requests': '1',
            })

            try:
                await page.goto(url, wait_until="networkidle", timeout=60000)
            except Exception:
                # If networkidle times out, try with domcontentloaded
                await page.goto(url, wait_until="domcontentloaded", timeout=30000)

            # Wait for specific selector if provided
            if wait_selector:
                try:
                    await page.wait_for_selector(wait_selector, timeout=wait_timeout)
                except Exception:
                    # Continue even if selector not found
                    pass

            # Get rendered HTML
            result["html"] = await page.content()

            # Get all visible text
            result["text"] = await page.inner_text("body")

            # Extract script contents for embedded JSON
            scripts = await page.query_selector_all("script")
            for script in scripts:
                content = await script.inner_text()
                result["scripts"].append(content)

                # Try to parse as JSON
                try:
                    json_data = json.loads(content)
                    result["json_data"] = json_data
                except (json.JSONDecodeError, ValueError):
                    pass

            # Also look for JSON in window/app state
            try:
                # Common patterns for embedded state
                patterns = [
                    r'window\.__NEXT_DATA__\s*=\s*({.+?});',
                    r'window\.__NUXT__\s*=\s*({.+?});',
                    r'window\.INITIAL_STATE\s*=\s*({.+?});',
                    r'__APOLLO_STATE__\s*=\s*({.+?});',
                ]

                for pattern in patterns:
                    matches = re.findall(pattern, result["html"], re.DOTALL)
                    for match in matches:
                        try:
                            json_data = json.loads(match)
                            if not result["json_data"]:
                                result["json_data"] = json_data
                            else:
                                # Merge if already exists
                                result["json_data"].update(json_data)
                        except (json.JSONDecodeError, ValueError):
                            pass
            except Exception:
                pass

            # Store network requests if captured
            if capture_network:
                result["network_requests"] = requests

            # Extract data using CSS selectors if any are provided
            # (This allows more reliable extraction than text patterns)
            # Callers can use this by implementing their own selector logic
            result["page"] = page  # Store page object for selector access

        finally:
            await context.close()
            await browser.close()

    return result


def extract_from_text(text: str, patterns: Dict[str, str]) -> Dict[str, Any]:
    """
    Extract values from text using regex patterns.

    Args:
        text: The text to search
        patterns: Dict mapping field names to regex patterns

    Returns:
        Dict of extracted values
    """
    result = {}
    for field, pattern in patterns.items():
        match = re.search(pattern, text, re.IGNORECASE)
        if match:
            value = match.group(1) if match.groups() else match.group(0)
            # Try to convert to int if possible
            try:
                result[field] = int(value)
            except ValueError:
                result[field] = value
    return result


def extract_from_json(json_data: Dict[str, Any], paths: Dict[str, List[str]]) -> Dict[str, Any]:
    """
    Extract values from JSON data using key paths.

    Args:
        json_data: The JSON data to search
        paths: Dict mapping field names to list of key paths to try

    Returns:
        Dict of extracted values
    """
    result = {}
    for field, key_paths in paths.items():
        for path in key_paths:
            try:
                value = json_data
                for key in path:
                    if isinstance(value, dict):
                        value = value.get(key)
                    elif isinstance(value, list) and key.isdigit():
                        value = value[int(key)]
                    else:
                        value = None
                        break

                if value is not None:
                    result[field] = value
                    break
            except (KeyError, TypeError, AttributeError):
                continue
    return result
