#include<iostream>
#include<vector>
#include<cstring>
#define MAX 1001
using namespace std;

typedef struct _Info{
    int node;
    int dist;
}Info;

vector<Info> v[MAX];
bool visited[MAX];

int dfs(int node, int dist, int find){
    visited[node] = true;
    if(node == find) return dist;
    for(auto& i : v[node]){
        if(visited[i.node]) continue;
        int n = dfs(i.node, dist+i.dist, find);
        if(n != -1) return n;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m, a, b, c;
    
    cin >> n >> m;
    for(int i=0; i<n-1; i++){
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    
    while(m--){
        cin >> a >> b;
        cout << dfs(a, 0, b) << '\n';
        memset(visited, false, sizeof(visited));
    }
}