// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
typedef long long ll;
using namespace std;

vector<ll> int_spliter(ll n){
    vector<ll> result;
    while(n){
        result.push_back(n%10);
        n /= 10;
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll sum, cnt = 0;    
    vector<ll> splited;
    char n;

    while(cin >> n){
        splited.push_back(n - '0');
    }

    while(splited.size() > 1){
        sum = 0;
        for(ll i = 0; i < splited.size(); i++){
            sum += splited[i];
        }
        splited = int_spliter(sum);
        cnt++;
    }
    
    cout << cnt << '\n';
    cout << (sum%3==0 ? "YES" : "NO") << '\n';
}