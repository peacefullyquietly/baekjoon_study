#include<iostream>
using namespace std;
 
int N, M;
typedef struct _Info{
    int left, right;
    int ans;
    int len;
}Info;
int arr[200001];
Info tree[800001];
 
inline Info set(Info& left, Info& right, int left_l, int right_l){
    Info node;
    
    node.len = left.len + right.len;
    
    node.left = left.left;
    if(left.len == left_l) node.left += right.left;
    
    node.right = right.right;
    if(right.len == right_l) node.right += left.right;

    node.ans = max(max(left.ans, right.ans), max(max(node.left, node.right),left.right+right.left));
    return node;
}
 
void update(int node, int start, int end, int idx, int val){
    if(start > idx || end < idx) return;
    if(end == start){
        tree[node] = {val, val, val, val};
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);
    tree[node] = set(tree[node*2], tree[node*2+1], mid-start+1, end-mid);
}
 
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int a;
        cin >> a;
        arr[a] ^= 1;
        if (a > 1) update(1, 1, N, a - 1, arr[a - 1] != arr[a]);
        if (a < N) update(1, 1, N, a, arr[a] != arr[a + 1]);
        cout << tree[1].ans+1 << '\n';
    }
}