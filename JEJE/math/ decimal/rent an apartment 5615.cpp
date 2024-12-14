#include<iostream>
#define ll unsigned long long
using namespace std;

ll A, base[3] = {2, 7, 61};

ll pow(ll x, ll y, ll mod){
    ll tmp = 1;
    x %= mod;
    while(y){
        if(y&1) tmp = (tmp*x)%mod;
        y >>= 1;
        x *= x;
        x %= mod;
    }
    return tmp;
}

bool isPrime(ll n, ll a){
    if(a%n == 0) return true;
    ll k = n-1;
    while(!(k&1)){
        if(pow(a, k, n) == n-1) return true;
        k >>= 1;
    }
    ll tmp = pow(a, k, n);
    return (tmp == 1 || tmp == n-1);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll tc, cnt = 0, tmp;
    cin >> tc;
    tmp = tc;
    while(tmp--){
        cin >> A;
        for(auto& i : base){
            if(!isPrime(A*2+1, i)){
                cnt++;
                break;
            }
        }
    }
    cout << tc - cnt << '\n';
}