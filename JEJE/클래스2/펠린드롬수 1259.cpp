// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s, cs;
    while(cin >> s)
    {
        if (s == "0") break;
        cs = s;
        reverse(s.begin(),s.end());
        if(s == cs) cout << "yes";
        else cout << "no";
        cout << '\n';
    }
}