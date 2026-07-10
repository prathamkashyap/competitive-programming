#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// APPROACH 1 --> Results in TLE
void countFactors(int n) {
  int factorCount = 0;
    for (int i=2; i*i<=n; i++) {
      if (n % i == 0) {
        factorCount++;
        if (n/i != i)
          factorCount++;
      }
  
      if (factorCount >= 2) 
        break;
    }
  
    if (factorCount == 1) {
      cout << "YES" << endl;
    }
  
    else {
      cout << "NO" << endl;
    }
}

// APPROACH 2 --> Find perfect squares
void perfectSquareFinder(long long n) {
  long long s = sqrt(n);
  bool isPrime = true;

  if (s < 2) {
    cout << "NO" << endl;
    return;
  }

  for (int i=2; i*i<=s; i++) {
    if (s%i == 0) {
      isPrime = false;
      break;
    }
  }

  if (s*s == n && isPrime) {
    cout << "YES" << endl;
  }
  else  
    cout << "NO" << endl;
}

// APPROACH 3 --> Sieve of Erastosthenes

const int MAX = 1000000;
vector<bool> prime(MAX + 1, true);

void sieve() {
    prime[0] = prime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (prime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                prime[j] = false;
        }
    }
}

void solve(long long n) {
    long long s = sqrt(n);

    if (s * s == n && prime[s])
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
  // int t;
  // cin >> t;

  // while (t--) {
  //   long long n;
  //   cin >> n;
    
    // countFactors(n);
    // perfectSquareFinder(n);

    sieve();

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;
        solve(n);
    }
    
  // }
  return 0;
}