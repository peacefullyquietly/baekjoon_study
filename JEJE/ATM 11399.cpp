// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans = 0;
    cin >> n;
    while(cin >> n) v.push_back(n);
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) ans+=v[i]*(v.size()-i);
    cout << ans << '\n';
}