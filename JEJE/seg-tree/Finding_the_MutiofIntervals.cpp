#include<iostream>
#define ll long long
#define MOD 1000000007
using namespace std;

ll tree[4000001];
ll arr[1000001];

ll init(int node, int start, int end){
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;
    return tree[node] = (init(node*2, start, mid) * init(node*2+1, mid+1, end))%MOD;
}

ll intervalMulti(int node, int start, int end, int left, int right){
    if(start > right || end < left) return 1;
    if(start >= left && end <= right) return tree[node];
    int mid = (start+end)/2;
    return (intervalMulti(node*2, start, mid, left, right)*intervalMulti(node*2+1, mid+1, end, left, right))%MOD;
}

void update(int node, int start, int end, int idx, ll value){
    if(start > idx || end < idx) return;
    if(end == start) {
        arr[idx] = value;
        tree[node] = value;
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, value);
    update(node*2+1, mid+1, end, idx, value);
    tree[node] = (tree[node*2]*tree[node*2+1])%MOD;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, m, k;
    cin >> n >> m >> k;
    
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    init(1,0,n-1);

    for(int i = 0; i < m+k; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1) {
            update(1, 0, n-1, b-1, c);
        }else {
            cout << intervalMulti(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
}