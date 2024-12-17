// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool sum(int a, int b, int c)
{
    if(a*a == b*b + c*c) return true;
    else return false;
}

int main()
{
    vector<int> v(3);
    while(cin >> v[0])
    {
        if(v[0] == 0) break;
        for(int i = 1; i < 3; i++)cin >> v[i];
        sort(v.begin(), v.end());
        if(sum(v[2], v[1], v[0])) cout << "right";
        else cout << "wrong";
        cout << '\n';
    }
}