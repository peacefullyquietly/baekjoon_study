// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b=0;
    int cnt = 5;
    while(cnt--)
    {
        cin >> a;
        b += a*a;
    }
    cout << b%10 <<'\n';
}