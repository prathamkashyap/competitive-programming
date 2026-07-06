#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long calculateSum(vector<int>& a) {
    long long sum = 0;
    int minVal = a[0];
    for(int i = 0; i < a.size(); i++) {
        minVal = min(minVal, a[i]);
        sum += minVal;
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        long long minSum = calculateSum(a);
        
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                vector<int> temp = a;
                temp[i] += temp[j];
                temp[j] = 0;
                minSum = min(minSum, calculateSum(temp));
            }
        }
        
        cout << minSum << endl;
    }
    return 0;
}