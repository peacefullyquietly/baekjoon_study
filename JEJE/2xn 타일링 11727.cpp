// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>

using namespace std;

int main()
{
    int n, arr[1001];
    cin >> n;
    arr[1] = 1; arr[2] = 3;
    for(int i = 3; i <= n; i++) arr[i] = (arr[i-1] + arr[i-2]*2)%10007;
    cout << arr[n] << '\n';
}