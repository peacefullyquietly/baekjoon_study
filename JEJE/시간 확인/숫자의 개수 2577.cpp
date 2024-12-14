// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
using namespace std;

int cnt[10];

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    string s = to_string(a*b*c);
    for(auto &i : s) cnt[i-'0'] += 1;
    for(auto &i : cnt) cout << i << '\n';
}