// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define p pair<int, int>
#define MAX 801
using namespace std;

vector<p> map[MAX];
int dist[MAX];
int N, V;

int dijkstra(int start, int end){
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<p, vector<p>, greater<p>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cur = pq.top().second, w = pq.top().first;
        pq.pop();
        if(dist[cur] < w) continue;
        for(auto& i : map[cur]){
            int next = i.first, add = i.second;
            if(dist[next] > dist[cur] + add){
                dist[next] = dist[cur] + add;
                pq.push({dist[next], next});
            }
        }
    }
    return dist[end];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int INF, _INF[1];
    memset(_INF, 0x3f, sizeof(_INF));
    INF = _INF[0];

    cin >> N >> V;
    for(int i=0; i<V; i++){
        int a, b, c;
        cin >> a >> b >> c;
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }
    int v1, v2;
    cin >> v1 >> v2;
    long long mid = dijkstra(v1, v2);
    long long case1 = dijkstra(1, v1) + mid + dijkstra(v2, N);
    long long case2 = dijkstra(1, v2) + mid + dijkstra(v1, N);
    
    long long ans = min(case1, case2);
    cout << (ans >= INF ? -1 : ans) << '\n';
}