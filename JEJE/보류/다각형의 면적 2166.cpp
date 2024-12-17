// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cmath>
#define MAX 10001
using namespace std;
double x[MAX], y[MAX];
 
int main()
{
    ios_base_sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    x[n] = x[0];
    y[n] = y[0];
    double ans = 0;
    for(int i = 0; i < n; i++) ans += x[i]*y[i+1];
    for(int i = 1; i <= n; i++) ans -= x[i]*y[i-1];
    cout << fixed;
    cout.precision(1);
    cout<< round((abs(ans)/2)*10)/10 << '\n';
}