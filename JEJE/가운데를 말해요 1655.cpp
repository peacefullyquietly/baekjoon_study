// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<int> maxh;
    priority_queue<int, vector<int>, greater<int>> minh;
    int n;
    cin >> n;
    cin >> n;
    maxh.push(n);
    cout << maxh.top() << '\n';
    while(cin >> n)
    {
        if(maxh.size() > minh.size())minh.push(n);
        else maxh.push(n);

        if(maxh.top() > minh.top())
        {
            int a=maxh.top();
            int b=minh.top();
            maxh.pop();minh.pop();
            maxh.push(b);
            minh.push(a);
        }
        cout << maxh.top() << '\n';
        //cout << "=====\n";
    }
}