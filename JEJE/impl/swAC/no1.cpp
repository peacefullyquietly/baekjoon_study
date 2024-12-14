#include<bits/stdc++.h>
#define MAX 10001
using namespace std;

int find_layer(int n){
    return (int)round(sqrt(n*2));
}

int find_l_k(int a, int b, int gap){
    return a + (b+gap-2)*(b+gap-1)/2 - (b-1)*b/2;
}

void solve(int tc){
    int s, e;
    cin >> s >> e;
    int tmp = s;
    s = (s < e) ? s : e; // s는 항상 작은 값(위에 존제)
    e = (tmp < e) ? e : tmp;
    
    int s_layer = find_layer(s);
    int e_layer = find_layer(e);
    int gap = e_layer - s_layer + 1;
    int l_k = find_l_k(s, s_layer, gap);
    int r_k = l_k + gap - 1;

    int ans;
    if(e >= l_k && e <= r_k){
        ans = gap;
    }else{
        if(e < l_k){
            ans = gap + (l_k - e);
        }else{
            ans = gap + (e - r_k);
        }
    }
    cout << "#" << tc+1 << ' ' << ans-1 << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    for(int i=0; i<tc; i++){
        solve(i);
    }
}