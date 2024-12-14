#include<iostream>
using namespace std;
 
int N, Q, U, V;
typedef struct _Info{
    long long left, right;
    long long max;
    long long sum;
}Info;
long long arr[100001];
Info tree[400001];
 
Info set(Info& left, Info& right){
    Info node;
    node.left = max(left.left, left.sum+right.left);
    node.right = max(right.right, right.sum+left.right);
    node.sum = left.sum + right.sum;
    node.max = max(max(left.max, right.max), left.right+right.left);
    return node;
}
 
void init(int node, int start, int end){
    if(start == end){
        int tmp = U*arr[start]+V;
        // cout << tmp << "\n";
        tree[node] = {tmp, tmp, tmp, tmp};
        return;
    }else{
        int mid = (start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        tree[node] = set(tree[node*2], tree[node*2+1]);   
    }
}
 
void update(int node, int start, int end, int idx, int val){
    if(start > idx || end < idx) return;
    if(end == start){
        arr[idx] = val;
        int tmp = U*arr[start]+V;
        tree[node] = {tmp, tmp, tmp, tmp};
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);
    tree[node] = set(tree[node*2], tree[node*2+1]);
}
 
Info max_continuos_sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {(long long)(-1e17), (long long)(-1e17), (long long)(-1e17), 0};
    if(left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    Info a = max_continuos_sum(node*2, start, mid, left, right);
    Info b = max_continuos_sum(node*2+1, mid+1, end, left, right);
    return set(a, b);
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> Q >> U >> V;
    
    for(int i = 0; i < N; i++){
        cin >> arr[i];
        arr[i] = arr[i];
    }

    init(1, 0, N-1);

    for(int i = 0; i < Q; i ++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 0){
            cout << max_continuos_sum(1, 0, N-1, b-1, c-1).max-V << "\n";
        }else{
            update(1, 0, N-1, b-1, c);
        }
    }
}