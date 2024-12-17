// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<map>
using namespace std;
typedef long long l; 
l N, P, Q, X, Y;
map<l,l> m;

l DDP(l n)
{
    if(n <= 0) return 1;
    if(m[n]) return m[n];
    m[n] = DDP(n/P-X)+DDP(n/Q-Y);
    return m[n];
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> P >> Q >> X >> Y;
    m[0] = 1;
    cout << DDP(N) << '\n';
}