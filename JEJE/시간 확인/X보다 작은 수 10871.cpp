// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, flag, n;
    cin >> tc >> flag;
    vector<int> v(tc);
    for(auto &i : v) cin >> i;
    for(auto &i : v) if(i < flag) cout << i << ' ';
    cout << '\n';
}