// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<algorithm>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
    int N;
    scanf("%d",N);
    vector<int> a(N);
    for(auto &i: a) scanf("%d",&i);
    scanf("%d",&N);
    vector<int> m(N);
    for(auto &i: m) scanf("%d",&i);
    
    sort(a.begin(), a.end());

    for(auto& i : m)
    {
        if(binary_search(a.begin(), a.end(), i)) printf("%d\n",1);
        else printf("%d\n",0);
        printf("");
    }    
}