// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b;
    while(true)
    {
        cin >> a >> b;
        if (a==0 && b==0) break;
        cout << a+b <<'\n';
    }
}