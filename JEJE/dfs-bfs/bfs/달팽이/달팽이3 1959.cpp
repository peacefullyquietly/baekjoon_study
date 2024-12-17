// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
using namespace std;
int main(){
    long long m,n,d,s;
    
    cin>>m>>n;
    s = min(m, n);
    d=2*(s-1);
    if(m>n)cout<<d+1;
    else cout<<d;
    cout<<'\n';
        if(m==n){
                if(m%2==0L){
                    cout << (m/2)+1 << ' ' << n/2;
                }
                else{
                    cout << (m/2)+1 << ' ' << (m/2)+1;
                }
        } else {
            if(s%2==0L){
                cout << s-(s/2-1) << ' ' << s-s/2;
            }
            else{
                cout << m-(s/2) << ' ' << n-(s/2);
            }
        }
    cout<<'\n';
    }