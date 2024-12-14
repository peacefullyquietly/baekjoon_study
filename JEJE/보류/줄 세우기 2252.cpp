#include<iostream>
#include<vector>
#include<queue>
const int MAX = 100001;
using namespace std;

int N, M, ent[MAX];
vector<int> list[MAX];

void tsort()
{
    queue<int> q;
    for(int i = 1; i <= N; i++) if(ent[i] == 0) q.push(i);

    while(!q.empty())
    {
        int node = q.front(); q.pop();
        cout << node << ' ';
        for(auto &i : list[node])
        {
            ent[i]--;
            if(ent[i] == 0)q.push(i);
        }
    }
    cout << '\n';
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
    tsort();
}