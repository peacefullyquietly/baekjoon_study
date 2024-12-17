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
    int n;
    cin >> n;
    while(cin >> n)v.push_back(n);
    if(prev_permutation(v.begin(), v.end())) for(auto &i : v) cout << i << ' ';
    else cout << -1;
    cout << '\n';
}