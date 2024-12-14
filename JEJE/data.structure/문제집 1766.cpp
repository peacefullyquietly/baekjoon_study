#include<iostream>
#include<queue>
#include<vector>
#define MAX 32001
using namespace std;
typedef pair<int, int> p;

vector<int> list[MAX];
int N, M, ent[MAX];

int topologysort()
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 1; i <= N; i++) if(ent[i] == 0) pq.push(i);
    while(!pq.empty())
    {
        int n = pq.top(); pq.pop();
        cout << n << ' ';
        for(auto &i : list[n])
        {
            ent[i]--;
            if(ent[i] == 0) pq.push(i);
        }
    }
    cout << '\n';
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    while(M--)
    {
        int a, b;
        cin >> a >> b;
        list[a].push_back(b);
        ent[b]++;
    }
    topologysort();
}