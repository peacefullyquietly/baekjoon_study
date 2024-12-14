#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc1, tc, sum[100001] = {0,};
    vector<int> v;
    cin >> tc >> tc1;
    v.resize(tc);
    for(auto &i : v) cin >> i;
    for(int i = 1; i <= v.size(); i++)sum[i] = sum[i-1]+v[i-1];
    
    int a,b;
    while(tc1--)
    {
        cin >> a >> b;
        cout << sum[b]-sum[a-1] << '\n';
    }
}