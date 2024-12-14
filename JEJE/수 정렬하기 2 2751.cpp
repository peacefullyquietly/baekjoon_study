// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    set<int> v;
    cin >> n;
    while(cin >> n) v.insert(n);
    for(auto &i : v) cout << i << '\n';
}