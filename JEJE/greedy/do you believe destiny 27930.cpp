// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    queue<char> kr, yon;

    for(auto& i : "KOREA"){
        kr.push(i);
    }

    for(auto& i : "YONSEI"){
        yon.push(i);
    }

    cin >> s;
    for(auto& i : s){
        if(kr.front() == i){
            kr.pop();
        }
        if(yon.front() == i){
            yon.pop();
        }

        if(kr.size() == 1){
            cout << "KOREA\n";
            break;
        }
        else if(yon.size() == 1){
            cout << "YONSEI\n";
            break;
        }
    }
}