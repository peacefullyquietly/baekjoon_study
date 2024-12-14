// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;
typedef unsigned long long l;
vector<l> v;

l cut(int size)
{
    l all = 0;
    if(size != 0) for(auto &i : v)all += i/size;
    else all = v.size();
    return all;
}

int main()
{
    l N, answer = 0, mid = 0, bottom = 0, top = 0, K;
    cin >> K >> N;
    v.resize(K);
    for(auto &i : v)
    {
        cin >> i;
        top = max(top, i);
    }
    while(bottom <= top)
    {
        mid = (bottom + top)/2;
        if(N <= cut(mid))
        {
            bottom = mid + 1;
            answer = max(answer, mid);
        }
        else
        {
            top = mid -1;
        }
    }
    cout << answer << '\n';
}