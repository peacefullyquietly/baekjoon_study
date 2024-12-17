// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<int, vector<int>, greater<int>> pq;
    int tc, n;
    cin >> tc;
    while(tc--)
    {
        cin >> n;
        pq.push(n);
    }

    n = 0;
    while(!pq.empty() && ( n == 0 || n+1 >= pq.top()))
    {
        n += pq.top();
        pq.pop();
    }
    cout << n+1 << '\n';
}