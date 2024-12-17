// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
using namespace std;

deque<int> q;
vector<int> order;
vector<int> v;

void order1(){
    int tmp = q.front();
}

void order2(){
    if(q.size() >= 2){
        int tmp = q.front();
        q.pop_front();
        int _tmp = q.back();
        q.pop_back();
        q.push_back(tmp);
        q.push_back(_tmp);
    }
}

void order3(){

}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    order.resize(n);
    for(int i = 0; i < n; i++){
        cin >> order[i];
        v.push_back(i+1);
    }
    reverse(order.begin(), order.end());
    for(auto &i : order){
        switch (i)
        {
        case 1:
            order1();
            break;
        case 2:
            order2();
            break;
        case 3:
            order3();
            break;
        default:
            break;
        }
    }
}