// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    unsigned long long n, sum = 0, r = 1;
    string s;
    cin >> n;
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        unsigned long word = s[i]-'a'+1;
        //cout << word << "*";
        //cout << pow(31,i) << "\n";
        sum += word*r;
        sum %= 1234567891;
        r *= 31;
        r %= 1234567891;
    }
    cout << sum << '\n';
}