// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#define l long long
#define k for(l j=0;j<K;j++)
using namespace std;int main(){ios_base::sync_with_stdio(0);cin.tie(0);l n,K,q;cin>>n>>K>>q;l tem,ans=0;k{cin>>tem;ans+=tem-1;}if(ans==0)ans+=n;for(l i=2;i<=n;i++){k{cin>>tem;ans+=i<=tem?tem-i:n-i+tem;}}cout<<(ans/n<=q?1:0);}