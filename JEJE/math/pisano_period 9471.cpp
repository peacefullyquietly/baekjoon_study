// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

long long pisano_period(long long m)
{

    int fa = 0, fb = 1, fc = -1;

    for (int i = 0; i <= (m*m)-1; i++){
        fc = (fa + fb) % m;
        fa = fb;
        fb = fc;
        if (fa == 0 && fb == 1) return i + 1;
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;

    while(tc--){
        long long n, m;
        cin >> n >> m;
        cout << n << ' ' << pisano_period(m) << '\n';
    }
}