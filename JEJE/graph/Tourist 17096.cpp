// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define MAX 500001
#define ll long long
#define p pair<ll, ll>
using namespace std;

vector<p> lis[MAX];
ll n, m;
ll dist[MAX];
ll cost[MAX];

void dijkstra(){
    priority_queue<p, vector<p>, greater<>> pq;
    for(int i = 0; i <= n; i++){
        dist[i] = 250000000000 + 1;
    }
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        ll cur = pq.top().second, w = pq.top().first;
        pq.pop();
        if(w > dist[cur]) continue;
        for(auto& i : lis[cur]){
            ll next_n = i.first, next_w = i.second;
            if(w + next_w < dist[next_n]){
                cost[next_n] = next_w;
                dist[next_n] = w + next_w;
                pq.push({w + next_w, next_n});
            }else if(w + next_w == dist[next_n]){
                cost[next_n] = min(cost[next_n], next_w);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        lis[a].push_back({b, c});
        lis[b].push_back({a, c});
    }

    dijkstra();

    ll ans = 0;
    for(int i = 1; i <= n; i++){
        ans += cost[i];
    }
    cout << ans << '\n';
}