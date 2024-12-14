#include<iostream>
using namespace std;
 
int N, M;
typedef struct _Info{
    int left, right;
    int max;
    int sum;
}Info;
int arr[100001];
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
        int tmp = arr[start];
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
 
// void update(int node, int start, int end, int idx, int val){
//     if(start > idx || end < idx) return;
//     if(end == start){
//         arr[idx] = val;
//         int tmp = arr[start];
//         tree[node] = {tmp, tmp, tmp, tmp};
//         return;
//     }
//     int mid = (start+end)/2;
//     update(node*2, start, mid, idx, val);
//     update(node*2+1, mid+1, end, idx, val);
//     tree[node] = set(tree[node*2], tree[node*2+1]);
// }
 
Info max_continuos_sum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {(int)(-1e9), (int)(-1e9), (int)(-1e9), 0};
    if(left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    Info a = max_continuos_sum(node*2, start, mid, left, right);
    Info b = max_continuos_sum(node*2+1, mid+1, end, left, right);
    return set(a, b);
}
 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
 
    init(1, 0, N-1);
 
    cin >> M;
    for(int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;
        cout << max_continuos_sum(1, 0, N-1, a-1, b-1).max << '\n';
    }
}