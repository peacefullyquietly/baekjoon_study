// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
typedef unsigned long long ll;

ll phi(ll n) {
    ll result = n;
    //if(n == 1) return 0;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }
    if (n > 1) {
        result -= result / n;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    cout << phi(n) << "\n";
}