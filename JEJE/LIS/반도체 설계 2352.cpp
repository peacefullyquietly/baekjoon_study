// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    vector<int> lis, input(40000);
    cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        cin >> input[i];
        if(lis.empty() || lis.back() < input[i]) lis.push_back(input[i]);
        else
        {
            int idx = lower_bound(lis.begin(), lis.end(), input[i]) - lis.begin();
            lis[idx] = input[i];
        }
    }
    cout << lis.size() << '\n';
}