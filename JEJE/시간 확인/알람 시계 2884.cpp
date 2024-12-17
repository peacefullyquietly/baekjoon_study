// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    b -= 45;
    if(b<0)
    {
        a -= 1;
        b += 60;
    }
    if(a < 0) a+=24;
    cout << a << ' ' << b;
}