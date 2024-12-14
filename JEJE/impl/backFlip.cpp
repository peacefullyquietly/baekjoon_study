#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    cin>>s;
    int zero_cnt = 0, one_cnt = 0;
    char prev = s[0];

    for(auto c : s){
        if(c == prev){
            continue;
        }
        
        if(prev == '0'){
            zero_cnt++;
        }else{
            one_cnt++;
        }

        prev = c;
    }

    if(prev == '0'){
        zero_cnt++;
    }else{
        one_cnt++;
    }

    cout<<min(zero_cnt, one_cnt)<<'\n';
}