// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> a, b;
    int tc, sum = 0;
    cin >> tc;
    a.resize(tc); b.resize(tc);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(a.begin(),a.end(), greater<>());
    sort(b.begin(),b.end(), less<>());
    for(int i = 0; i < tc; i++) sum += a[i]*b[i];
    cout << sum << '\n';
}