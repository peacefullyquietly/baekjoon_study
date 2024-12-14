// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<pair<int,int>> q;
    int n;
    for(int i = 1; i <= 9; i++)
    {
        cin >> n;
        q.push({n,i});
    }
    cout << q.top().first << '\n';
    cout << q.top().second << '\n';
}