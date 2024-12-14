// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    queue<int> q;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)q.push(i);
    while(1 != q.size())
    {
        q.pop();

        n = q.front();
        q.pop();
        q.push(n);
    }
    cout << q.front() << '\n';
}