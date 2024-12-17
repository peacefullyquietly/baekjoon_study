// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
string s;
vector<pair<int, string>> v;

bool cmp(pair<int, string>a, pair<int, string>b)
{
    return a.first < b.first;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int old; string s;
    cin >> old;
    while(cin >> old >> s) v.push_back({old, s});
    stable_sort(v.begin(), v.end(), cmp);
    for(auto &i : v)cout << i.first << ' ' << i.second << '\n';
}