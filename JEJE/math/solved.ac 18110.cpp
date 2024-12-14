// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    int tc;
    vector<int> v;
    
    cin >> tc;
    if (tc == 0){
        cout << 0 << '\n';
        return 0;
    }
    
    while(tc--){
        int n;
        cin >> n;
        v.push_back(n);
    }

    sort(v.begin(), v.end());

    int sum = 0, cnt = 0, cut = round(v.size()*0.15);
    for(int i = cut; i < v.size() - cut; i++){
        sum += v[i];
        cnt++;
    }

    cout << round((double)sum/cnt) << '\n';
}