#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int prev;
    cin >> prev;
    
    int currentLength = 1;
    int maxLength = 1;
    
    for (int i = 1; i < n; i++) {
        int curr;
        cin >> curr;
        
        if (curr >= prev) {
            currentLength++;
            maxLength = max(maxLength, currentLength);
        } else {
            currentLength = 1;
        }
        
        prev = curr;
    }
    
    cout << maxLength << endl;
    return 0;
}
