// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

int tmp_arr[1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    string s;
    long long n, jinju = -1, cnt = 0;
    bool jinjuSet = false;
    for(int i = 0; i < tc; i++){
        cin >> s >> n;
        if(s == "jinju") {
            jinju = n;
            jinjuSet = true;
            continue;
        }

        if (!jinjuSet) {
            if(n <= 1000) tmp_arr[n]++;
            else cnt++;
        } else {
            if (n > jinju) cnt++;
        }
    }
    
    if (jinjuSet) {
        for(int i = jinju+1; i <= 1000; i++) {
            cnt += tmp_arr[i];
        }
    }

    cout << jinju << '\n';
    cout << cnt << '\n';
}