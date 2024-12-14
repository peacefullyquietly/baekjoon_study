#include<iostream>
#include<vector>
#include<queue>
#define MAX 10001
using namespace std;
typedef pair<int,int> p;

vector<p> list[MAX];
int N, ent[MAX];
priority_queue<p,vector<p>,greater<p>> pq;

int topology()
{
    int ans = 0;
    while(!pq.empty())
    {
        int w = pq.top().first, n = pq.top().second;
        ans = max(w, ans);
        pq.pop();
        for(auto &i : list[n])
        {
            ent[i.second]--;
            if(ent[i.second] == 0)pq.push({i.first+w, i.second});
        }
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int b = 1; b <= N; b++)
    {
        int t, a, taken;
        cin >> t >> taken;
        ent[b] = taken;
        if(taken == 0) pq.push({t,b});
        while(taken--)
        {
            cin >> a;
            list[a].push_back({t,b});
        }
    }
    cout << topology() << '\n';
}