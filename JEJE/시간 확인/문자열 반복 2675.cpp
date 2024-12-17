// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        string s, input;
        cin >> n >> input;
        for(auto&j : input){
            for(int i = 0; i < n; i++)
            {
                s.push_back(j);
            }
        }
        cout << s << '\n';
    }
}