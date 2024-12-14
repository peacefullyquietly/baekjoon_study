// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b, v, cnt;
    cin >> a >> b >> v;
    if((v-a)%(a-b) == 0) cnt = (v-a)/(a-b)+1;
    else cnt = (v-a)/(a-b);
    cout << cnt <<'\n';
}