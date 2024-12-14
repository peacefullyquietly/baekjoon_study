#include<iostream>
#define MAX 246913
using namespace std;

bool filter[MAX];

void init(){
    filter[1] = true;
    for(int i = 2; i*i <= MAX; i++){
        if(filter[i]) continue;
        for(int j = i+i; j <= MAX; j+=i){
            filter[j] = true;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    init();
    while(1){
        cin >> n;
        if(n == 0) break;
        int cnt = 0;
        for(int i = n+1; i <= 2*n; i++){
            if(!filter[i]) cnt++;
        }
        cout << cnt << "\n";
    }
}