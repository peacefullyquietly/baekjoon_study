// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int n, m;
vector<int> tr[MAX];
int parent[MAX][20];
int depth[MAX], max_depth;

void set_tr(int node, int pnode, int d){
    depth[node] = d;
    parent[node][0] = pnode;
    for(int i = 1; i <= max_depth; i++){
        parent[node][i] = parent[parent[node][i-1]][i-1];
    }

    for(auto next : tr[node]){
        if(next == pnode) continue;
        set_tr(next, node, d+1);
    }
}

inline int LCA(int a, int b){
    if(a == b) return a;
    if (a == 1 || b == 1) return 1;
    depth[a]<depth[b]?swap(a, b):void();

    if(depth[a] != depth[b]){
        for(int i = max_depth; i >= 0; i--){
            if(depth[a] - depth[b] >= (1<<i)){
                a = parent[a][i];
            }
        }
    }

    int lca = a;
    if(a != b){
        for(int i = max_depth; i >= 0; i--){
            if(depth[a] >= (1<<i) && parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
            lca = parent[a][i];
        }
    }
    return lca;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b;
    cin >> n;
    for(int i = 0; i < n-1; i++){
        cin >> a >> b;
        tr[a].push_back(b);
        tr[b].push_back(a);
    }

    max_depth = (int)floor(log2(MAX));
    set_tr(1, 0, 1);
    cin >> m;
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}