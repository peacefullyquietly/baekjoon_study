#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int query, ans = 0;
    cin >> query;
    while(query--){
        int a;
        cin >> a;
        ans += a;
    }
    cout << ans;
}