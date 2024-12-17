// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int tc;
    while(cin >> tc)
    {
        vector<int> input(100000), length;
        for(int i = 0; i < tc; i++)
        {
            cin >> input[i];
            if(length.empty() || length.back() < input[i]) length.push_back(input[i]);
            else
            {
                int idx = lower_bound(length.begin(), length.end(), input[i]) - length.begin();
                length[idx] = input[i];           
            }
        }
        cout << length.size() << '\n';
    }
}