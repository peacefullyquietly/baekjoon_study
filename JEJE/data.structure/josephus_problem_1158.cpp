#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k;
    queue<int> q;

    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        q.push(i);
    }

    cout << '<';
    int cnt = 1;
    while(!q.empty()){
        if(cnt%k == 0){
            cout << q.front();
            if(q.size() != 1){
                cout << ", ";
            }
        }else{
            q.push(q.front());
        }
        q.pop();
        cnt++;
    }
    cout << '>';
}