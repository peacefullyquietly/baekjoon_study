#include<iostream>
#define ll long long
using namespace std;

ll counter(ll num, ll div){
    int cnt = 0;
    while (num > 0){
        cnt += num/div;
        num /= div;
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, m;
    cin >> n >> m;
    ll expo_two = counter(n, 2) - counter(n-m, 2) - counter(m, 2);
    ll expo_five = counter(n, 5) - counter(n-m, 5) - counter(m, 5);

    cout << min(expo_two, expo_five) << '\n';
}