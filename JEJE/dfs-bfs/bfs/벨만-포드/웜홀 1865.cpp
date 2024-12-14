#include<iostream>
#include<string>
#include<vector>
#define MAX 1000000000;
using namespace std;

int n, m, w;

struct Info{
    int s, e, t;
}; vector<Info> v;

bool Bellmanford()
{
    int d[501];
    for(auto &i : d) i = MAX;
    for(int i = 1; i <= n; i++){
        for(auto &i : v){
            int s = i.s;
            int e = i.e;
            int t = i.t;
            if(d[s]+t < d[e]) d[e] = d[s]+t;
        }
    }

    for(auto &i : v)
    {
        int s = i.s;
        int e = i.e;
        int t = i.t;
        if(d[s]+t < d[e]) return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        v.clear();
        int s, e, t;
        cin >> n >> m >> w;
        for(int i = 0; i < m; i++)
        {
            cin >> s >> e >> t;
            v.push_back({s, e, t});
            v.push_back({e, s, t});
        }
        for(int i = 0; i < w; i++)
        {
            cin >> s >> e >> t;
            v.push_back({s, e, -t});
        }
        if(Bellmanford()) cout << "YES";
        else cout << "NO";
        cout << '\n';
    }

}