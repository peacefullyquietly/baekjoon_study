// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<queue>
#include<iostream>

using namespace std;
priority_queue<int> heep;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int order;
    cin >> order;
    while(cin >> order)
    {
        if(order == 0){
            if(!heep.empty()){
                cout << heep.top();
                heep.pop();
            }else cout << 0;
            cout << '\n';
        }else heep.push(order);
    }
}