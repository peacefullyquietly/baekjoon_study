// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
    #include<bits/stdc++.h>
    using namespace std;

    int main(){
        ios_base::sync_with_stdio(0);cin.tie(0);
        long long tc; cin >> tc;
        vector<long long> v;
        for(long long k = 1; k <= tc; k++){
            long long n; cin >> n;
            v.clear();
            v.resize(n*2);
            for(auto &i : v){
                cin >> i;
            }

            cout << "#" << k << " ";
            for(auto &i : v){
                long long idx = lower_bound(v.begin(), v.end(), (i/3)*4) - v.begin();
                if(idx == v.size()) continue;
                if(v[idx] == (i/3)*4){
                    cout << i << " ";
                    v[idx] = 0;
                }
            }
            cout << "\n";
        }
        return 0;
    }