// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;

struct Info{
    int a, b, c;
};

Info twoP (vector<ll>& v)
{
    Info index;
    ll sum, flag = 3000000001;
    int start, end = v.size()-1;
    for(int second = 0; second < end-1; second++)
    {
        start = second+1;
        end = v.size()-1;
        while(start < end)
        {
            sum = v[start] + v[second] + v[end];
            if(abs(sum) < flag)
            {
                index = {second, start, end};
                if(sum == 0) return index;
                flag = abs(sum);
            }

            if(sum < 0){
                start++;
            }else{
                end--;
            }
        }
    }
    return index;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<ll> v;
    int tc;
    cin >> tc;
    v.resize(tc);
    for(auto &i : v) cin >> i;
    sort(v.begin(), v.end());
    Info ans = twoP(v);
    cout << v[ans.a] << ' ' << v[ans.b] << ' ' << v[ans.c] << '\n';
}