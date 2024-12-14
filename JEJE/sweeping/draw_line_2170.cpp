#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    v.resize(n);
    for(auto &i : v){
        cin >> i.first >> i.second;
    }
    sort(v.begin(), v.end());
    int ans = 0, s = v[0].first, e = v[0].second;
    for(int i = 1; i < v.size(); i++){
        if(v[i].first < e){
            e = max(e,v[i].second);
        }else{
            ans += e-s;
            s = v[i].first;
            e = v[i].second;
        }
    }
    ans += e-s;

    cout << ans;
}