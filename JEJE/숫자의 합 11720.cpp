// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
int main()
{
    int tc, sum = 0;
    char n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        sum += (int)n - '0';
    }
    cout << sum << '\n';
}