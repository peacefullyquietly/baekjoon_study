// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

unordered_map<string, string> friendship;
unordered_map<string, int> cnt;

string find(string a){
    if(friendship[a] == a){
        return a;
    }else{
        return friendship[a] = find(friendship[a]);
    }
}

void uni(string a, string b){
    a = find(a);
    b = find(b);
    if (a != b) {
        friendship[b] = a;
        cnt[a] += cnt[b];
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        friendship.clear();
        cnt.clear();
        int n;
        cin >> n;
        while(n--){
            string a, b;
            cin >> a >> b;
            if(!friendship.count(a)){
                friendship[a] = a;
                cnt[a] = 1;
            }
            if(!friendship.count(b)){
                friendship[b] = b;
                cnt[b] = 1;
            }
            uni(a, b);
            cout << cnt[find(a)] << '\n';
        }
    }
}