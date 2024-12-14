// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<algorithm>
#include<vector>
#define index second
#define MAX 500001
using namespace std;

vector<pair<int,int>> arr;
int tree[MAX*4  ];

// int init(int node, int start, int end){
//     if(start == end) return tree[node] = 1;
//     int mid = (start+end)/2;
//     return tree[node] = init(node*2, start, mid)+init(node*2+1, mid+1, end);
// }

int getSwap(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    return getSwap(node*2, start, mid, left, right) + getSwap(node*2+1, mid+1, end, left, right);
}

void update(int node, int start, int end, int index) {
    if (index < start || index > end) return;
    if (end == start) {
        tree[node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index);
    update(node * 2 + 1, mid + 1, end, index);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        arr.push_back({a, i});
    }
    sort(arr.begin(), arr.end());
    // init(1, 0, n-1);
    long long ans = 0;
    for(int i = 0; i < n; i++){
        ans += getSwap(1, 0, n-1, arr[i].index, n-1);
        update(1, 0, n-1, arr[i].index);
    }
    cout << ans << '\n';
}