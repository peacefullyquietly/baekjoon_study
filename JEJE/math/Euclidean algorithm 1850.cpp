// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include <numeric>
#define long unsigned long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    long a, b;
    cin >> a >> b;
    int _gcd = gcd(a,b);
    for(int i = 0; i < _gcd; i++){
        cout << 1;
    }
    cout << '\n';
}