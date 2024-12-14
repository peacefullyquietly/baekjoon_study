// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
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