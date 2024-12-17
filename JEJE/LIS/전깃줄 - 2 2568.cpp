// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, n, m, maxim = 0;;
    vector<pair<int, int>> input;
    vector<int> length, ldx(100000);
    cin >> tc;
    while(cin >> n >> m) input.push_back({n, m});
    sort(input.begin(), input.end());
    for(int i = 0; i < tc; i++)
    {
        int num = input[i].second;
        if(length.empty() || length.back() < num)
        {
            length.push_back(num);
            ldx[i] = length.size()-1;
        }
        else
        {
            int idx = lower_bound(length.begin(), length.end(), num) - length.begin();
            length[idx] = num;
            ldx[i] = idx;
        }
        if(ldx[i] > ldx[maxim]) maxim = i;
    }
    set<int> happy;
    for (int i = maxim + 1; i < tc; i++) happy.insert(input[i].first);
    for(int i = maxim; i >= 0; i--)
    {
        //cout << i << "<>" << maxim << "\n";
        if (i == maxim || (input[i].second < input[maxim].second && ldx[i] == ldx[maxim] - 1)) maxim = i;
        else happy.insert(input[i].first);
    }

    cout << tc-length.size() << '\n';
    for(auto &i : happy) cout << i << '\n';
}