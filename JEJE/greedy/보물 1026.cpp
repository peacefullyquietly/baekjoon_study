#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> a, b;
    int tc, sum = 0;
    cin >> tc;
    a.resize(tc); b.resize(tc);
    for(auto &i : a) cin >> i;
    for(auto &i : b) cin >> i;
    sort(a.begin(),a.end(), greater<>());
    sort(b.begin(),b.end(), less<>());
    for(int i = 0; i < tc; i++) sum += a[i]*b[i];
    cout << sum << '\n';
}