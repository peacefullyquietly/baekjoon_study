// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int a, b, c; cin >> a >>b >> c;
    cout << min(min(a / 40, b / 50), c / 30);
}