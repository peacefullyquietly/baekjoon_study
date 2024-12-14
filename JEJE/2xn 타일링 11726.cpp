// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, arr[1001];
    cin >> n;
    arr[1] = 1; arr[2] = 2;
    for(int i = 3; i <= n; i++) arr[i] = (arr[i-1]+arr[i-2])%10007;
    cout << arr[n] << '\n';
}