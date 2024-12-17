// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    vector<int> v(10);
    for(auto &i : v)
    {
        cin >> n;
        i = n%42;
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << v.size() << '\n';
}