// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int com(int n, int r)
{
    if(n == r || r == 0) return 1;
    if(r > n-r) return com(n, n-r);
    return com(n-1, r) + com(n-1, r-1);
}

int main()
{
    int n, r;
    cin >> n >> r;
    cout << com(n, r) << '\n';
}