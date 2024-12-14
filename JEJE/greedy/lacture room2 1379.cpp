#include<bits/stdc++.h>
#define p pair<int, int>
using namespace std;

typedef struct _Info{
    int num, start, end;
}Info;

bool comp(Info a, Info b){
    if(a.start == b.start){
        return a.end < b.end;
    }

    return a.start < b.start;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    priority_queue<p, vector<p>, greater<>> pq;
    vector<int> room;
    vector<Info> v;
    int n, a, b, c, ans = 0;
    
    cin >> n;
    room.resize(n+1);
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        v.push_back({a,b,c});
    }

    sort(v.begin(), v.end(), comp);

    pq.push({v[0].end, v[0].num});
    room[v[0].num] = ans+1;
    ans++;

    for(int i = 1; i < n; i++){
        if(pq.top().first <= v[i].start){
            room[v[i].num] = room[pq.top().second];
            pq.pop();
        }else{
            ans++;
            room[v[i].num] = ans;
        }
        pq.push({v[i].end, v[i].num});
    }

    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
        cout << room[i] << '\n';
        // cout << i << ':' << room[i] << '\n';
    }
}