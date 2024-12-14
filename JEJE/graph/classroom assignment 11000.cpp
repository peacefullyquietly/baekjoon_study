#include<bits/stdc++.h>
#define p pair<int, int>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    priority_queue<int, vector<int>, greater<>> pq;
    vector<p> v;

    int n, ans = 0;

    cin >> n;
    v.resize(n);
    for(auto &i : v){
        cin >> i.first >> i.second;
    }

    sort(v.begin(), v.end());
    
    pq.push(v[0].second);
    ans++;

    for(int i = 1; i < n; i++){
        if(pq.top() <= v[i].first){
            pq.pop();
        }else{
            ans++;
        }
        pq.push(v[i].second);
    }

    cout << ans <<'\n';
}