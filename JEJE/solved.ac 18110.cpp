// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while(cin >> n)v.push_back(n);
    sort(v.begin(), v.end());
    
}