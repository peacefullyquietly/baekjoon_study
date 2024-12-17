// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> v;
    int n, m;
    cin >> n >> m;
    while(cin >> n)v.push_back(n);
    sort(v.begin(), v.end());
    cout << v[m-1] << '\n';
}