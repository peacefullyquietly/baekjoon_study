#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 10000
using namespace std;

vector<int> prime;

void init(){
    bool filter[MAX];

    filter[1] = true;
    for(int i = 2; i*i <= MAX; i++){
        if(filter[i]) continue;
        for(int j = i+i; j <= MAX; j+=i){
            filter[j] = true;
        }
    }
    
    for(int i = 2; i <= MAX; i++){
        if(!filter[i]) prime.push_back(i);
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, tc;
    init();
    cin >> tc;
    while(tc--){
        cin >> n;
        pair<int, int> ans = {20000,0}, tmp;
        for(int i = 0; i < prime.size(); i++){
            if(!binary_search(prime.begin(), prime.end(), n-prime[i])) continue;
            tmp.first = prime[i];
            tmp.second = n-prime[i];
            if(abs(tmp.first-tmp.second) < abs(ans.first-ans.second)) ans = tmp;
        }
        cout << ans.first << " " << ans.second << "\n";
    }
}