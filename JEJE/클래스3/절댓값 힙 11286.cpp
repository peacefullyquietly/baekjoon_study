// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
using namespace std;
typedef pair<int,int> p;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<p,vector<p>,greater<p>> q;
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        if(abs(n) > 0)q.push({abs(n),n});
        else
        {
            if(q.empty())
            {
                cout << 0 << '\n';
                continue;
            }
            cout << q.top().second << '\n';
            q.pop();
        }
    }
}