#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, dp[MAX][5][5];
vector<int> v;
int cost[5][5] = {
    {1, 2, 2, 2, 2},
    {0, 1, 3, 4, 3},
    {0, 3, 1, 3, 4},
    {0, 4, 3, 1, 3},
    {0, 3, 4, 3, 1}
};

int dfs(int n, int left, int right){
    if (n > v.size()-1) return 0;
    if (left == right && left > 0) return 1e9;
    
    int &tmp = dp[n][left][right];
    if(tmp == -1){
        tmp = min(dfs(n+1, v[n], right)+ cost[left][v[n]],
                 dfs(n+1, left, v[n]) + cost[right][v[n]]);
    }
    
    return tmp;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    while(true){
        cin >> n;
        if (n == 0) break;
        v.push_back(n);
    }
    
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 0, 0) << '\n';
}