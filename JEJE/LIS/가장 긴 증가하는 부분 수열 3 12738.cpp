#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    long long n;
    vector<long long> v, a;
    cin >> n;
    while(cin >> n)v.push_back(n);
    for(auto i = 0; i < v.size(); i++)
    {
        if(a.empty()||a.back() < v[i])a.push_back(v[i]);
        else
        {
            int idx = lower_bound(a.begin(), a.end(), v[i]) - a.begin();
            a[idx] = v[i];
        }
    }
    cout << a.size() << '\n';
}