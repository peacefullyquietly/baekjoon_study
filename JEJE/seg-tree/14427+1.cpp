// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define p pair<int,int>
#define MAX 1000000001
using namespace std;

int arr[100001];
p mint[400001], maxt[400001];

void init(int node, int start, int end){
    if(start == end){
        mint[node].first = maxt[node].first = arr[start];
        mint[node].second = maxt[node].second = start;
    }else{
        int mid = (start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        mint[node] = min(mint[node*2], mint[node*2+1]);
        maxt[node] = max(maxt[node*2], maxt[node*2+1]);
    }
}

pair<p, p> intervalMinMax(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {{MAX, -1},{-MAX, -1}};
    if(left <= start && right >= end) return {mint[node], maxt[node]};
    int mid = (start+end)/2;
    pair<p, p> a = intervalMinMax(node*2, start, mid, left, right);
    pair<p, p> b = intervalMinMax(node*2+1, mid+1, end, left, right);
    // cout << min(a.first, b.first) << " " << max(a.second, b.second) << "=\n";
    return {min(a.first, b.first), max(a.second, b.second)};
}

void update(int node, int start, int end, int idx, int val){
    if (idx < start || idx > end) return;
    if (end == start) {
        arr[idx] = val;
        mint[node].first = maxt[node].first = val;
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);
    mint[node] = min(mint[node*2], mint[node*2+1]);
    maxt[node] = max(maxt[node*2], maxt[node*2+1]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    init(1, 0, n-1);

    cin >> m;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(a == 1){
            update(1, 0, n-1, b-1, c);
        }else{
            pair<p, p> ans = intervalMinMax(1, 0, n-1, b-1, c-1);
            cout << ans.first.second+1 << "\n";
            // cout << ans.first << '\n';
        }
    }
}