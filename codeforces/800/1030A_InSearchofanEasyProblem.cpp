#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int response;
    bool isHard = false;
    for (int i = 0; i < n; i++) {
        cin >> response;
        if (response == 1) {
            isHard = true;
        }
    }
    if (isHard)
        cout << "HARD" << "\n";
    else
        cout << "EASY" << "\n";
    return 0;
}
