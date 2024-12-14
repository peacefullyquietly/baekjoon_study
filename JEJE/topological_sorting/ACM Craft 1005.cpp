// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define MAX 1001
using namespace std;

int D[MAX];
int cnt[MAX];
int dp[MAX];
vector<int> list[MAX];
queue<int> q;

void topological_sort(){
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto& i : list[node]){
            cnt[i]--;
            dp[i] = max(dp[i], dp[node]+D[i]);
            if(cnt[i] == 0) q.push(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int w, tc, n, k;
    cin >> tc;
    while(tc--){
        
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> D[i];
            dp[i] = D[i];
        }

        for(int i = 0; i < k; i++){
            int a, b;
            cin >> a >> b;
            list[a].push_back(b);
            cnt[b]++;
        }

        for(int i = 1; i <= n; i++){
            if(cnt[i] == 0) q.push(i);
        }

        cin >> w;
        topological_sort();

        cout << dp[w] << '\n';

        memset(D, 0, sizeof(D));
        memset(cnt, 0, sizeof(cnt));
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; i++){
            list[i].clear();
        }
    }
}