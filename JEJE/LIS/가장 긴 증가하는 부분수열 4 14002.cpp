// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
    int tc, idx, big_idx = 0;;
    vector<int> lis, input(1000), ldx(1000);
    cin >> tc;
    for(int i = 0; i<tc;i++)
    {
        cin >> input[i];
        if(lis.empty() || lis.back() < input[i])
        {
            lis.push_back(input[i]);
            ldx[i] = lis.size()-1;
        }
        else
        {
            idx = lower_bound(lis.begin(), lis.end(), input[i]) - lis.begin();
            lis[idx] = input[i];
            ldx[i] = idx;
        }
        if(ldx[i] > ldx[big_idx]) big_idx = i;
    }
    
    stack<int> happy;
    happy.push(input[big_idx]);
    for(int i = big_idx; i >= 0; i--)
    {
        if(input[i] < input[big_idx] && ldx[i] == ldx[big_idx]-1)
        {
            happy.push(input[i]);
            big_idx = i;
        }
    }

    cout << lis.size() << '\n';
    while(!happy.empty())
    {
        cout << happy.top() << ' ';
        happy.pop();
    }
    cout << '\n';

}
