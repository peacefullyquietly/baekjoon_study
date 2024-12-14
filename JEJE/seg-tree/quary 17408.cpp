// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<algorithm>
#define MAX 100001
#define a first
#define b second
#define p pair<int, int>
using namespace std;

p tree[4*MAX];
int arr[MAX];

p max_p(p a, p b){
    p tmp;
    a = {max(a.a, a.b), min(a.a, a.b)};
    b = {max(b.a, b.b), min(b.a, b.b)};

    if(a.a > b.a){
        tmp.a = a.a;
        tmp.b = max(a.b, b.a);
    }
    else{
        tmp.a = b.a;
        tmp.b = max(a.a, b.b);
    }
    return tmp;
}

void init(int node, int start, int end){
    if(start == end){
        tree[node] = {arr[start], 0};
        return;
    }
    int mid = (start+end)/2;
    init(node*2, start, mid);
    init(node*2+1, mid+1, end);
    tree[node] = max_p(tree[node*2], tree[node*2+1]);
}

void update(int node, int start, int end, int index, int value){
    if(index < start || index > end) return;
    if(start == end){
        tree[node] = {value, 0};
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, index, value);
    update(node*2+1, mid+1, end, index, value);
    tree[node] = max_p(tree[node*2], tree[node*2+1]);
}

p ans(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {0, 0};
    if(left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    return max_p(ans(node*2, start, mid, left, right), ans(node*2+1, mid+1, end, left, right));
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    init(1, 0, n-1);
    cin >> m;
    while(m--){
        int order, i, j;
        cin >> order >> i >> j;
        if(order == 1){
            update(1, 0, n-1, i-1, j);
        }else{
            p tmp = ans(1, 0, n-1, i-1, j-1);
            cout << tmp.a+tmp.b << "\n";
        }
    }
    // p a = {2, 3};
    // p b = {4, 1};
    // // p a = {2, 5};
    // // p b = {2, 6};
    // cout << max_p(a, b).a << max_p(a, b).b << "\n";
}