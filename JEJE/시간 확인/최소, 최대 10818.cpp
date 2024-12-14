// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<int> max;
    priority_queue<int, vector<int>, greater<int>> low;
    int n;
    cin >> n;
    while(cin >> n)
    {
        max.push(n);
        low.push(n);
    }
    cout << low.top() << ' ' << max.top() << '\n';
}