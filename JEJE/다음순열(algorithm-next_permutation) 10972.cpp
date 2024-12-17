// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<algorithm>
#include<vector>
#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n, per[10000];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> per[i];
    if (next_permutation(per, per+n))
    {
        for(int i = 0; i < n; i++) cout << per[i] << ' ';
    }
    else cout << -1;
    cout << '\n';
}