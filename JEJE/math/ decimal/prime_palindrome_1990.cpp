#include<bits/stdc++.h>
#define MAX 10000000
using namespace std;

bool not_prime[MAX];
int a, b;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> a >> b;
    b = min(b, MAX);

    for(int i = 2; i * i <= b; i++){
        if(not_prime[i]) continue;
        for(int j = i*2; j <= b; j += i){
            not_prime[j] = true;
        }
    }

    for(int i = a; i <= b; i++){
        if(not_prime[i]) continue;

        string s1 = to_string(i);
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        if (s1 == s2) cout << i << '\n';
    }
    cout << -1;
}