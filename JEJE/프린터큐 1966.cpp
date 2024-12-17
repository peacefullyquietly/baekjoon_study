// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<queue>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n, want, num, cnt = 0;
        deque<pair<int, int>> q;
        priority_queue<int> pq;
        cin >> n >> want; //want is start 0
        for(int i = 0; i < n; i++)
        {
            cin >> num; 
            q.push_back({num, i});
            pq.push(num);
        }
        while(true)
        {
            if (q.front().first != pq.top())
            {
                q.push_back(q.front());
                q.pop_front();
            }
            else
            {
                pq.pop();
                cnt += 1;
                if (q.front().second == want) break;
                q.pop_front();
            }
        }
        cout << cnt << "\n";
    }
}