// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unordered_set>

using namespace std;

typedef unsigned long long ll;

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll pollard_rho(ll n) {
    ll x = rand() % (n - 2) + 2;
    ll y = x;
    ll c = rand() % (n - 1) + 1;
    ll d = 1;
    while (d == 1) {
        x = (x * x + c) % n;
        y = (y * y + c) % n;
        y = (y * y + c) % n;
        x = abs((long long)(x - y));
        d = gcd(x, n);
        if (d == n) return pollard_rho(n);
    }
    return d;
}

unordered_set<ll> get_factors(ll n) {
    unordered_set<ll> factors;
    if (n == 1) return factors;
    if (n % 2 == 0) {
        factors.insert(2);
        while (n % 2 == 0) n /= 2;
    }
    while (n != 1) {
        ll factor = pollard_rho(n);
        factors.insert(factor);
        while (n % factor == 0) n /= factor;
    }
    return factors;
}

ll phi(ll n) {
    unordered_set<ll> factors = get_factors(n);
    ll result = n;
    for (ll factor : factors) {
        result -= result / factor;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin >> n;
    cout << phi(n) << "\n";
    return 0;
}