#include<iostream>
using namespace std;

int n, x;
int v[100001];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int ans = 2147483647;
    
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    for(int i = 0; i < n-1; i++){
        ans = min(ans, (v[i]+v[i+1])*x);
    }

    cout << ans << '\n';
}