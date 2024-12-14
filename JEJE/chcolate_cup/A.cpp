// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;

string tail(string s){
    s.erase(0, 1);
    return s;
}

string prime(string &s){
    return s.substr(0, ceil((double)s.length()/(double)3));
}

string rev(string s){
    reverse( s.begin(), s.end());
    return s;
}
bool is3LayerCake(string &str){
    string condition[4];
    string s_prime = prime(str);
    string rv_s_prime = rev(s_prime);
    condition[0] = s_prime + rv_s_prime + s_prime;
    condition[1] = s_prime + tail(rv_s_prime) + s_prime;
    condition[2] = s_prime + rv_s_prime + tail(s_prime);
    condition[3] = s_prime + tail(rv_s_prime) + tail(s_prime);

    for(auto &i : condition){
        if(str == i){
            return true;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    string str;
    cin >> tc;
    while(tc--){
        cin >> str;
        cout << is3LayerCake(str) << '\n';
    }
}