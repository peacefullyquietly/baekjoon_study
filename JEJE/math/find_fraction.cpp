// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <string>

using namespace std;

std::string find_fraction(int n) {
    int layer = 1, cnt = 1;
    while (cnt < n) {
        layer++;
        cnt += layer;
        }

    if(layer % 2 == 0)
        return to_string(layer-(cnt-n)) + "/" + to_string(cnt-n+1);
    else
        return to_string(cnt-n+1) + "/" + to_string(layer-(cnt-n));
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    cout << find_fraction(n) << '\n';
}