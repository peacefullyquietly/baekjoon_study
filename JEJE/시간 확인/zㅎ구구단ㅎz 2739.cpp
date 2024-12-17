// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= 9; i++)
    {
        cout << n << " * " << i << " = " << n*i;
        cout << '\n';
    }
}