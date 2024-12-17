// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--)
    {
        map<string, int> m;
        string s;
        int tc2, sum = 1;
        cin >> tc2;
        while (tc2--)
        {
            cin >> s >> s;
            m.insert({s,0});
            m[s] += 1;
        }
        for(auto &i : m) sum *= i.second+1;
        cout << sum-1 << '\n';
    }
}