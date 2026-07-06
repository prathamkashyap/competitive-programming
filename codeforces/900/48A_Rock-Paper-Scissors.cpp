#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string f,m,s; 
    cin >> f >> m >> s;
    set<string> st{f,m,s};

    if(st.size()==1 || st.size()==3){
        cout << "?\n";
        return 0;
    }

    // two same, one different
    if(f==m && s!=f){
        if((s=="rock" && f=="scissors") ||
           (s=="scissors" && f=="paper") ||
           (s=="paper" && f=="rock"))
            cout << "S\n";
        else cout << "?\n";
    }
    else if(f==s && m!=f){
        if((m=="rock" && f=="scissors") ||
           (m=="scissors" && f=="paper") ||
           (m=="paper" && f=="rock"))
            cout << "M\n";
        else cout << "?\n";
    }
    else if(m==s && f!=m){
        if((f=="rock" && m=="scissors") ||
           (f=="scissors" && m=="paper") ||
           (f=="paper" && m=="rock"))
            cout << "F\n";
        else cout << "?\n";
    }
    else cout << "?\n";
}
