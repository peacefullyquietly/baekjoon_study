// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, num;
    vector<int> v;
    cin >> tc;
    for (int i=0; i < tc; i++)
    {
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    if(v.size() != 1) cout << v.front()*v.back() << "\n";
    else cout << v[0]*v[0] << "\n";
    return 0;
}