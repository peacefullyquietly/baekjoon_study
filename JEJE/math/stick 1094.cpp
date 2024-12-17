// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x, len = 64, ans = 0;

    cin >> x;
    while(x > 0){
        if(len > x) len >>= 1;
        else{
            x -= len;
            ans++;
        }
    }
    cout << ans << "\n";
}