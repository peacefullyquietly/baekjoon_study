// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int E, S, M;
    int e=1, s=1, m=1;
    int cnt=1;
    cin >> E >> S >> M;
    while(1)
    {
        if(E == e && S == s && M == m)
        {
            cout << cnt << '\n';
            return 0;
        }
        e += 1; s += 1; m += 1;
        if(e > 15) e = 1;
        if(s > 28) s = 1;
        if(m > 19) m = 1;
        cnt += 1;
    }
}