// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int n;

int lets_do(int sum)
{
    // cout << sum << '\n';
    if(sum == n) return 1;
    else if(sum > n) return 0;
    int j = 0;
    for (int i = 1; i <= 3; i++)
    {
        j += lets_do(sum + i);
    }
    return j;
}

int main()
{
    cin >> n;
    while(cin >> n)
    {
        cout << lets_do(0) << '\n';
    }
}