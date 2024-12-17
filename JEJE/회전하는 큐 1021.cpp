// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#include<vector>

using namespace std;
deque<int> v;

void second()
{
    v.push_back(v.front());
    v.pop_front();
}

void third()
{
    v.push_front(v.back());
    v.pop_back();
}

int index(int i)
{
    for(int j = 0; j<v.size(); j++) if(i == v[j])return j;
}

int main()
{
    vector<int> order;
    int m, n, id, answer = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)v.push_back(i);
    while(cin >> n)order.push_back(n);
    for(auto &i : order)
    {
        if(v.front() == i);
        else
        {
            id = index(i);
            while(v.front() != i)
            {
                if(v.size()/2 >= id) second();
                else third();
                answer += 1;
            }
        }
        v.pop_front();
    }
    cout << answer << '\n';
}