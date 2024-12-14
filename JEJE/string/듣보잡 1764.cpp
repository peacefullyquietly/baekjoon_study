// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<map>
#include<set>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    map<string, bool> m;
    set<string> out;
    int N, M;
    string s;
    cin >> N >> M;
    while(N--)
    {
        cin >> s;
        m[s] = true;
    }
    while(M--)
    {
        cin >> s;
        if(m[s])out.insert(s);
    }
    cout << out.size() << '\n';
    for(auto &i : out) cout << i << '\n';
}