// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#define p pair<int,int>
#define MAX 1000000001
using namespace std;

int arr[100001];
int mint[400001], maxt[400001];

void init(int node, int start, int end){
    if(start == end){
        mint[node] = maxt[node] = arr[start];
    }else{
        int mid = (start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        mint[node] = min(mint[node*2], mint[node*2+1]);
        maxt[node] = max(maxt[node*2], maxt[node*2+1]);
    }
}

p intervalMinMax(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {MAX,-MAX};
    if(left <= start && right >= end) return {mint[node], maxt[node]};
    int mid = (start+end)/2;
    p a = intervalMinMax(node*2, start, mid, left, right);
    p b = intervalMinMax(node*2+1, mid+1, end, left, right);
    // cout << min(a.first, b.first) << " " << max(a.second, b.second) << "=\n";
    return {min(a.first, b.first), max(a.second, b.second)};
}

// void update(int node, int start, int end, int idx, int val){
//     if(start > idx || end < idx) return;
//     if(end == start){
//         arr[idx] == val;
//         mint[node] = maxt[node] = arr[start];
//         return;
//     }
//     int mid = (start+end)/2;
//     update(node*2, start, mid, idx, val);
//     update(node*2+1, mid+1, end, idx, val);
//     mint[node] = min(mint[node*2], mint[node*2+1]);
//     maxt[node] = max(maxt[node*2], maxt[node*2+1]);
// }

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    init(1, 0, n-1);

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        p ans = intervalMinMax(1, 0, n-1, a-1, b-1);
        cout << ans.second-ans.first << '\n';
    }
}