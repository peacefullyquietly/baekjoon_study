// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <bits/stdc++.h>
#define MAX 20001
using namespace std;

int v, e;
unordered_map<int, vector<int>> graph;
bool visited[MAX];
bool color[MAX];


bool isBipartite(){
    for(int i=1; i<=v; i++){
        for(auto& j : graph[i]){
            if(color[i] == color[j]){
                return false;
            }
        }
    }
    return true;
}

void fill(int start){
    bool flag = true;
    queue<int> q;
    q.push(start);
    visited[start] = true;
    color[start] = flag;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        flag = !color[node];
        for(auto& i : graph[node]){
            if(!visited[i]){
                visited[i] = true;
                color[i] = flag;
                q.push(i);
            }
        }
    }
}

void init(){
    graph.clear();
    memset(visited, false, sizeof(visited));
    memset(color, false, sizeof(color));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;

    while(tc--){
        cin >> v >> e;
        for(int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        for(int i = 1; i<=v; i++){
            if(!visited[i]){
                fill(i);
            }
        }
        cout << (isBipartite() ? "YES" : "NO") << '\n';

        init();
    }
}