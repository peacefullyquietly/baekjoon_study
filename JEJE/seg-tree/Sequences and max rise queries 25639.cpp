#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int N, Q;
int arr[100001];

typedef struct _Info{
    int min, max;
    int rise;
}Info;

Info tree[400001];

void init(int node, int start, int end){
    if(start == end){
        tree[node] = {arr[start], arr[start], 0};
    }else{
        int mid = (start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        tree[node].min = min(tree[node*2].min, tree[node*2+1].min);
        tree[node].max = max(tree[node*2].max, tree[node*2+1].max);
        tree[node].rise = max({tree[node*2+1].max-tree[node*2].min,  // 증가
                               tree[node*2].rise, tree[node*2+1].rise});
    }
}

void update(int node, int start, int end, int idx, int val){
    if(start > idx || end < idx) return;
    if(end == start){
        arr[idx] = val;
        tree[node] = {arr[start], arr[start], 0};
    }else{
        int mid = (start+end)/2;
        update(node*2, start, mid, idx, val);
        update(node*2+1, mid+1, end, idx, val);
        tree[node].min = min(tree[node*2].min, tree[node*2+1].min);
        tree[node].max = max(tree[node*2].max, tree[node*2+1].max);
        tree[node].rise = max({tree[node*2+1].max-tree[node*2].min,  // 증가
                               tree[node*2].rise, tree[node*2+1].rise});
    }
}

Info max_rise_squences(int node, int start, int end, int left, int right){
    if(start > right || end < left) return {INF, -INF, -INF};
    if(start >= left && end <= right) return tree[node];
    int mid = (start+end)/2;
    Info a = max_rise_squences(node*2, start, mid, left, right);
    Info b = max_rise_squences(node*2+1, mid+1, end, left, right);
    return{
        min(a.min, b.min),
        max(a.max, b.max),
        max({b.max-a.min, a.rise, b.rise})
    };
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }

    init(1, 0, N-1);

    cin >> Q;
    for(int i = 0; i < Q; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, N-1, b-1, c);
        }else{
            cout << max_rise_squences(1, 0, N-1, b-1, c-1).rise << '\n';
        }
    }
}