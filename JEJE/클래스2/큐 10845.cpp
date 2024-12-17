// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<queue>
#include<string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    queue<int> q;
    string s;
    int tc, n;
    cin >> tc;
    while(tc--)
    {
        cin >> s;
        if(s[1] == 'u'){
            cin >> n;
            q.push(n);
        }else if(s[1] == 'o'){
            if(q.empty()) cout << -1;
            else
            {
                cout << q.front();
                q.pop();
            }
        }else if(s[0] == 's'){
            cout << q.size();
        }else if(s[0] == 'e'){
            n = q.empty();
            cout << n;
        }else if(s == "front"){
            if(q.empty()) cout << -1;
            else cout << q.front();
        }else{
            if(q.empty()) cout << -1;
            else cout << q.back();
        }
        if(s[1] != 'u') cout << '\n';
    }
}