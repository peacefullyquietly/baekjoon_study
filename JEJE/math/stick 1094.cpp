#include<iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int x, len = 64, ans = 0;

    cin >> x;
    while(x > 0){
        if(len > x) len >>= 1;
        else{
            x -= len;
            ans++;
        }
    }
    cout << ans << "\n";
}