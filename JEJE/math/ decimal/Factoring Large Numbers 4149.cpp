// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#define ll unsigned long long
#define lll __int128
using namespace std;

lll pow(lll x, lll y, lll mod) {
    lll tmp = 1;
    x %= mod;
    while (y) {
        if (y & 1) tmp = (tmp * x) % mod;
        y >>= 1;
        x = (x * x) % mod;
    }
    return tmp;
}

ll gcd(ll a, ll b){
    if(a < b) swap(a, b);
    while(b != 0) {
        ll r = a%b;
        a = b;
        b = r;
    }
    return a;
}

bool _isPrime(ll n, ll a){
    if(a%n == 0) return true;
    ll k = n-1;
    while(!(k&1)){
        if(pow(a, k, n) == n-1) return true;
        k >>= 1;
    }
    ll tmp = pow(a, k, n);
    return (tmp == 1 || tmp == n-1);
}

bool isPrime(ll n){
    if(n == 2 || n == 3) return true;
    if(n%2 == 0) return false;

    ll a[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int i=0; i<12; i++)
        if(!_isPrime(n, a[i])) {
            return false;
            break;
        }
    return true;
}

ll findDiv(lll n){
    if(n%2 == 0) return 2;
    if(isPrime(n)) return n;

    lll x = rand()%(n-2) + 2, y = x, c = rand()%10 + 1, g = 1;
    while(g == 1){
        x = ((x*x)%n + c)%n;
        y = ((y*y)%n + c)%n;
        y = ((y*y)%n + c)%n;
        g = gcd(abs(x-y), n);
        if(g == n) return findDiv(n);
    }
    if(isPrime(g)) return g;
    else return findDiv(g);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    vector<ll> ans;
    cin >> n;
    while(n > 1){
        ll tmp = findDiv(n);
        ans.push_back(tmp);
        n /= tmp;
    }
    sort(ans.begin(), ans.end());
    for(auto& i : ans) cout << i << '\n';
}