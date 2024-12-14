// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    string s;
    cin >> tc;
    cin.ignore();
    while(tc--)
    {
        int add = 0, answer = 0;
        getline(cin, s);
        for(auto& i : s)
        {
            if(i == 'X') add = 0;
            else
            {
                add += 1;
                answer += add;
            }
        }
        if (answer < 0) answer = 0;
        cout << answer << '\n';
    }
}