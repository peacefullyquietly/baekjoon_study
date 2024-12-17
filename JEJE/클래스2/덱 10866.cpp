// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    deque<int> d;
    int n; string s;
    cin >> tc;
    while(tc--)
    {
        cin >> s;
        if(s[1] == 'u'){
            cin >> n;
            if(s[5] == 'f') d.push_front(n);
            else d.push_back(n);
        }else if(s[1] == 'o'){
            if(d.empty()) cout << -1;
            else
            {
                if(s[4] == 'f'){
                    cout << d.front();
                    d.pop_front();
                }else{
                    cout << d.back();
                    d.pop_back();
                }
            }
        }
        else if(s == "size") cout << d.size();
        else if(s == "front"){
            if(d.empty()) cout << -1;
            else cout << d.front();
        }else if(s == "back"){
            if(d.empty()) cout << -1;
            else cout << d.back();
        }else
        {
            n = d.empty();
            cout << n;
        }
        if(s[1] != 'u')cout << '\n';
    }
}