// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

int sum(vector<int> &v)
{
    int s = 0;
    for(int i = 1; i < v.size(); i++) s += abs(v[i]-v[i-1]);
    return s;
}

int main()
{
    vector<int> v;
    int n, answer;
    cin >> n;
    while(cin >> n)v.push_back(n);
    sort(v.begin(), v.end());
    answer = sum(v);
    while(next_permutation(v.begin(), v.end())) answer = max(answer, sum(v));
    cout << answer << '\n';
}