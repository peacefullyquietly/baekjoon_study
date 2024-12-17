// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

int T;
vector<int> v[2];
vector<int> sum[2];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> T;

    for(int i = 0; i < 2; i++){
        int n;
        cin >> n;
        v[i].resize(n);
        for(auto& j : v[i]){
            cin >> j;
        }
    }

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < v[i].size(); j++){
            int _sum = 0;
            for(int k = j; k < v[i].size(); k++){
                _sum += v[i][k];
                sum[i].push_back(_sum);
            }
        }
    }

    sort(sum[1].begin(), sum[1].end());

    long long ans = 0;
    for(auto& i : sum[0]){
        int tmp = T - i;
        auto start_idx = lower_bound(sum[1].begin(), sum[1].end(), tmp);
        auto end_idx = upper_bound(sum[1].begin(), sum[1].end(), tmp);
        ans += end_idx - start_idx;
    }
    cout << ans;

}