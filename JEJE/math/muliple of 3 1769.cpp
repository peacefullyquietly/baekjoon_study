#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    string s;
    ll n = 0, cnt = 0;
    
    cin >> s;

    if(s.size() > 1){
        for(auto& i : s){
            n += i-'0';
        }
        cnt++;
    }else{
        n = stoi(s);
    }
    
    while(n >= 10){

        ll tmp = 0;

        while(n >= 10){
            tmp += n % 10;
            n /= 10;
        }
        tmp += n;

        n = tmp;
        cnt ++;
    }

    cout << cnt << '\n' << (n % 3 == 0 ? "YES" : "NO") << '\n';
}