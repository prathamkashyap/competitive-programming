/**
 * @file template.cpp
 * @brief Universal Competitive Programming Boilerplate in C++
 * @author Pratham Kashyap
 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <numeric>
#include <iomanip>
#include <cassert>

using namespace std;

// Type Aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// Constants
constexpr ll INF64 = 2e18;
constexpr int INF32 = 1e9 + 7;
constexpr ll MOD = 1e9 + 7; // or 998244353
constexpr ld EPS = 1e-9;
constexpr ld PI = 3.14159265358979323846;

// Macros
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())
#define pb push_back
#define eb emplace_back
#define fi first
#define se second

// Math Functions
template<typename T>
T gcd(T a, T b) { return b == 0 ? a : gcd(b, a % b); }

template<typename T>
T lcm(T a, T b) { return (a / gcd(a, b)) * b; }

ll mod_exp(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (__int128)res * base % mod;
        base = (__int128)base * base % mod;
        exp /= 2;
    }
    return res;
}

ll mod_inv(ll n, ll mod = MOD) {
    return mod_exp(n, mod - 2, mod);
}

// Fast I/O Setup
void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(10);
}

// Problem Solution
void solve() {
    // Write your solution here
    
}

int main() {
    fast_io();
    
    int t = 1;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
