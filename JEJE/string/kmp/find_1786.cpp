// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

vector<int> getPi(string p){
    vector<int> pi(p.size(), 0);
    int j = 0;
    for(int i = 1; i < p.size(); i++){
        while(j > 0 && p[i] != p[j]){
            j = pi[j-1];
        }
        if(p[i]==p[j]){
            pi[i] = ++j;
        }
    }
    return pi;
}

vector<int> kmp(string T, string P){
    vector<int> ans;
    auto pi = getPi(P);
    int j = 0;
    for(int i = 0; i < T.size(); i++){
        while(j > 0 && T[i] != P[j]){
            j = pi[j-1];
        }
        if(T[i]==P[j]){
            if(j==P.size()-1){
                ans.push_back(i+1-P.size());
                j = pi[j];
            } else{
                j++;
            }
        }
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string T, P;
    getline(cin, T);
    getline(cin, P);
    auto ans = kmp(T, P);
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i+1 << ' ';
    }
}