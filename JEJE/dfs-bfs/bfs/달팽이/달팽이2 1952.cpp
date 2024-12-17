// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std; int main(){int m,n,d;cin>>m>>n;d=2*(min(m,n)-1);if(m>n)cout<<d+1;else cout<<d;cout<<'\n';}

// m = 열 n == 행