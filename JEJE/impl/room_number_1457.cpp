// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

int arr[10];

int main() {
    
    int n;
    cin >> n;
    
    while (n > 0) {
        arr[n % 10]++;
        n /= 10;
    }

    arr[6] = (arr[6] + arr[9] + 1) / 2;
    arr[9] = 0;

    int ans = 0;
    for (auto &i : arr) {
        ans = max(ans, i);
    }

    cout << ans;
}