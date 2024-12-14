#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie();
    vector<int> len, input(1000);
    vector<pair<int,int>> dp(1000);
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++)
    {
        cin >> input[i];
        if(len.empty() || len.back() < input[i])
        {
            len.push_back(input[i]);
            dp[i].first = len.size();

        }
        else
        {
            int idx = lower_bound(len.begin(), len.end(), input[i]) - len.begin();
            len[idx] = input[i];
            dp[i].first = idx+1;
        }
    }

    len.clear();
    
    for(int i = tc-1; i >= 0; i--)
    {
        if(len.empty() || len.back() < input[i])0
        {
            len.push_back(input[i]);
            dp[i].second = len.size();

        }
        else
        {
            int idx = lower_bound(len.begin(), len.end(), input[i]) - len.begin();
            len[idx] = input[i];
            dp[i].second = idx+1;
        }
    }
    int answer = 0;
    for(auto&i:dp)answer = max(i.first+i.second,answer);
    cout << answer-1 << '\n';
}