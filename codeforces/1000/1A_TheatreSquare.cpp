#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;
    
    long long rows = (long long)ceil((double)n / a);
    long long cols = (long long)ceil((double)m / a);
    
    cout << rows * cols << endl;
    
    return 0;
}
