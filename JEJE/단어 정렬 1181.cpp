// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
#include<set>
using namespace std;
struct Comp
{
    bool operator() (const string &a, const string &b)const
    {
        if(a.size() == b.size()) return a < b;
        else return a.size() < b.size();
    }
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    set<string, Comp> v;
    string s;
    cin >> s;
    while(cin >> s)v.insert(s);
    for(auto &i : v)cout<<i<<'\n';
}