// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<map>
using namespace std;
typedef long long l; 
l N, P, Q;
map<l,l> m;

l DDP(l n)
{
    if(m[n]) return m[n];
    m[n] = DDP(n/P)+DDP(n/Q);
    return m[n];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> P >> Q;
    m[0] = 1;
    cout << DDP(N) << '\n';
}