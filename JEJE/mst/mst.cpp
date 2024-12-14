#include<bits/stdc++.h>
#define MAX 100001
using namespace std;

int V, E, ans, u[MAX];

struct Info{
    int a, b, w;
    bool operator <(const Info &other) const{
        return w > other.w;
    }
};
priority_queue<Info> pq;


int find(int n){
    if(u[n] == n) return n;
    else return u[n] = find(u[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a == b) return;
    if(a < b) u[b] = a;
    else u[a] = b;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
}

int mst(){
    while(!pq.empty()){
        int a = pq.top().a, b = pq.top().b w = pq.top().w;
        pq.pop();
        if(find(a) != find(b)){
            
        }
    }
}