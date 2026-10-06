#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    string s;
    cin >> s;

    string answer;

    for (char c : s) {
        switch (c) {
            case '2':
                answer += "2";
                break;
            case '3':
                answer += "3";
                break;
            case '4':
                answer += "322";
                break;
            case '5':
                answer += "5";
                break;
            case '6':
                answer += "53";
                break;
            case '7':
                answer += "7";
                break;
            case '8':
                answer += "7222";
                break;
            case '9':
                answer += "7332";
                break;
        }
    }

    sort(answer.begin(), answer.end(), greater<char>());

    cout << answer << '\n';

    return 0;
}