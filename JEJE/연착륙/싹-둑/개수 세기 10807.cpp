// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int,int> m;
    int tc, n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        m[n] += 1;
    }
    cin >> n;
    cout << m[n] << '\n';
}