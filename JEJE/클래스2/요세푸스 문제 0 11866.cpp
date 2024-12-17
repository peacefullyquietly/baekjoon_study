// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    queue<int> q;
    int a, b;
    cin >> a >> b;
    for(int i = 1; i <= a; i++) q.push(i);

    cout << '<';

    while(!q.empty())
    {
        for(int i = 0; i < b-1; i++)
        {
            int fron_t;
            fron_t = q.front();
            q.pop();
            q.push(fron_t);
        }
        cout << q.front();
        if(1 != q.size())cout << ", ";
        q.pop();
    }

    cout << ">\n";
}