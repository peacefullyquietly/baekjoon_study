// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#define MAX 1000001
#define ll long long
using namespace std;

ll arr[MAX], tree[MAX*4], lazy[MAX*4];

ll init(int node, int start, int end){
    if(start==end) return tree[node]=arr[start];
    int mid=(start+end)/2;
    return tree[node]=init(node*2,start,mid)+init(node*2+1,mid+1,end);
}

void update_lazy(int node, int start, int end){
    if(!lazy[node]) return;
    tree[node] += lazy[node]*(ll)(end-start+1);
    if(start != end){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node]=0;
}

void update_tree(int node, int start, int end, int left, int right, ll diff){
    update_lazy(node, start, end);
    if(left > end || right < start) return;
    if (left <= start && end <= right) {
        tree[node] += diff*(ll)(end-start+1);
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    int mid=(start+end)/2;
    update_tree(node*2, start, mid, left, right, diff);
    update_tree(node*2+1, mid+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}

ll query(int node, int start, int end, int left, int right){
    update_lazy(node, start, end);
    if(left > end || right < start) return 0;
    if(left <= start && end <= right) return tree[node];
    int mid = (start+end)/2;
    return query(node*2, start, mid, left, right) + query(node*2+1, mid+1, end, left, right);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,m;
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    init(1, 0, n-1);
    cin >> m;
    while(m--){
        int a,b,c,d;
        cin >> a >> b;
        if(a-1){
            cout << query(1,0,n-1,b-1,b-1) << "\n";
        } else{
            cin >> c >> d;
            update_tree(1,0,n-1,b-1,c-1,d);
        }
    }
}