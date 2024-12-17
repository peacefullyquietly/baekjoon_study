// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> in;
vector<int> o;
bool use[10000];

void nm6()
{
    if(o.size() == M)
    {
        for(auto i : o) cout << i << ' ';
        cout << '\n';
        return;
    }
    for(auto j : in)
    {
        if(!use[j] && (o.empty() || o.back() < j))
        {
            use[j] = true;
            o.push_back(j);
            nm6();
            use[j] = false;
            o.pop_back();
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while(N--)
    {
        int dum;
        cin >> dum;
        in.push_back(dum);
    }
    sort(in.begin(), in.end());
    nm6();
    return 0;
}