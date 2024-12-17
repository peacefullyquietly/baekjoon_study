// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

int N, M;
vector<int> input;
vector<int> output;

void nm8()
{
    if(output.size() == M)
    {
        for(auto &i : output) cout << i << ' ';
        cout<< '\n';
        return;
    }
    for(auto &j : input)
    {
        if(output.empty() || output.back() <= j)
        {
            output.push_back(j);
            nm8();
            output.pop_back();
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    while(N--)
    {
        int dum;
        cin >> dum;
        input.push_back(dum);
    }
    sort(input.begin(), input.end());
    nm8();
    return 0;
}