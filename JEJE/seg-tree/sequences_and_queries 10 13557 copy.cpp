#include<iostream>
#define ll long long
using namespace std;
 
int N, M;
typedef struct _Info{
    ll left, right;
    ll max;
    ll sum;
}Info;
ll arr[100001];
Info tree[400001];
 
Info set(Info& left, Info& right){
    Info node;
    node.left = max(left.left, left.sum+right.left);
    node.right = max(right.right, right.sum+left.right);
    node.sum = left.sum + right.sum;
    node.max = max(max(left.max, right.max), left.right+right.left);
    return node;
}
 
void init(){
    for(int i = N-1; i > 0; i--){
        tree[i] = set(tree[i*2], tree[i*2+1]);
    }
}
 
Info max_continuos_sum(int left, int right){
    Info tmp = {(ll)(-1e17), (ll)(-1e17), (ll)(-1e17), 0};
    left += N;
    right += N;
    for(; left < right; left >>= 1, right >>= 1){
        if(left&1) tmp = set(tmp, tree[left++]);
        if(right&1) tmp = set(tmp, tree[--right]);
    }
    return tmp;
}

ll max_in_range(int x1, int y1, int x2, int y2){
    if(x2 <= y1){
        Info left = max_continuos_sum(x1, x2);
        Info mid = max_continuos_sum(x2, y1+1);
        Info right = max_continuos_sum(y1+1, y2+1);
        
        return(max(max(mid.max, left.right+mid.sum+right.left),
                   max(left.right+mid.left, mid.right+right.left)));
    }else{
        // cout << max_continuos_sum(x1, y1).right << " " << max_continuos_sum(y1, x2).sum << " " << max_continuos_sum(x2, y2).left << "\n";
        return max_continuos_sum(x1, y1+1).right, +
               max_continuos_sum(y1+1, x2).sum, +
               max_continuos_sum(x2, y2+1).left;
    }
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
 
    init();
 
    cin >> M;
    for(int i = 0; i < M; i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << max_in_range(a-1, b-1, c-1, d-1) << '\n';
    }
}