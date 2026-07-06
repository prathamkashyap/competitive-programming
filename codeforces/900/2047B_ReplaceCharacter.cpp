#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int arr[26][2];
    for (int i = 0; i < t; i++)
    {
        int k;
        cin >> k;
        char s[k];
        int maxe = 0, maxi = 0, minie = 50, minii = 0;
        for (int x = 0; x < 26; x++)
        {
            arr[x][0] = 0;
            arr[x][1] = 15;
        }
        for (int j = 0; j < k; j++)
        {
            cin >> s[j];
            int p = s[j] - 'a';
            arr[p][0] = arr[p][0] + 1;
            arr[p][1] = j;
            if (arr[p][0] > maxe)
            {
                maxe = arr[p][0];
                maxi = j;
            }
        }
        for (int g = 0; g < 26; g++)
        {
            if (arr[g][0] > 0)
            {
                if (arr[g][0] <= minie)
                {
                    minii = arr[g][1];
                    minie = arr[g][0];
                }
            }
        }

        if (minie == maxe)
        {
            int o = 0;
            while (s[o] == s[maxi])
            {
                o++;
            }
            if (o < k)
                s[o] = s[maxi];
        }
        else
        {
            s[minii] = s[maxi];
        }

        for (int j = 0; j < k; j++)
        {
            cout << s[j];
        }
        cout << endl;
    }
    return 0;
}
