// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

int main(){
    sort()
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    vector<int> v;
    
    cin >> n;
    v.resize(n);

    for(auto& i : v){
        cin >> i;
    }

    long long sum = 1e9+1e9, lft = 0, rgt = v.size()-1;
    pair<int, int> ans = {v[lft], v[rgt]};

    while(lft < rgt){
        if(abs(v[lft] + v[rgt]) < sum){
            ans = {v[lft], v[rgt]};
            sum = abs(v[lft] + v[rgt]);
        }

        if(v[lft] + v[rgt] == 0){
            break;
        }else if (v[lft] + v[rgt] < 0){
            lft++;
        }else if (v[lft] + v[rgt] > 0){
            rgt--;
        }
    }

    cout << ans.first << ' ' << ans.second;
}