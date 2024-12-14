#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> v;
    int n, m;
    cin >> n >> m;
    while(cin >> n)v.push_back(n);
    sort(v.begin(), v.end());
    cout << v[m-1] << '\n';
}