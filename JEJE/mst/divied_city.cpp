#include<iostream>
#include<queue>
#include<vector>
#define MAX 10001
using namespace std;
typedef pair<int, int> p;

int V, E, ans, u[MAX];
struct Info{
    int a, b, w;
    bool operator <(const Info &other) const{ return w > other.w;}
}; priority_queue<Info> pq;

int find(int n)
{
    if(u[n] == n) return n;
    else return u[n] = find(u[n]);
}

void merge(int a, int b)
{
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(a<b)u[b] = a;
    else u[a] = b; 
}

int mst()
{
    int cnt = pq.size();
    for(int i = 0; i < cnt-1; i++)
    {
        int a = pq.top().a, b = pq.top().b, w = pq.top().w;
        pq.pop();
        if (find(a) != find(b))
        {
            ans += w;
            merge(a, b);
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> V >> E;
    for(int i = 1; i <= V; i++) u[i] = i;
    while(E--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        pq.push({a, b, w});
    }
    cout << mst() << '\n';
}