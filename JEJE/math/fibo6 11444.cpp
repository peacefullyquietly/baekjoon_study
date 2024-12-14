#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long
using namespace std;

unordered_map<ll, ll> fibo = {{0, 0}, {1, 1}, {2, 1}};

ll fib(ll n){
    if(fibo.find(n) != fibo.end()) return fibo[n];
    if(!(n&1)){
        ll tmp = n / 2;
        return fibo[n] = ((2 * fib(tmp - 1) + fib(tmp)) * fib(tmp)) % MOD;
    }
    else{
        ll tmp = (n + 1) / 2;
        return fibo[n] = (fib(tmp) * fib(tmp) + fib(tmp - 1) * fib(tmp - 1)) % MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    cout << fib(n) << '\n';
}