// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<bits/stdc++.h>
#define p pair<int,int>
#define MAX 1000000001
using namespace std;

int arr[100001];
int oddt[400001], event[400001];

void init(int node, int start, int end){
    if(start == end){
        if(arr[start]%2 == 0){
            event[node] = 1;
            oddt[node] = 0;
        }else{
            event[node] = 0;
            oddt[node] = 1;
        }
    }else{
        int mid = (start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        oddt[node] = oddt[node*2] + oddt[node*2+1];
        event[node] = event[node*2] + event[node*2+1];
    }
}

p intervalMinMax(int node, int start, int end, int left, int right){
    if(left > end || right < start) return {0, 0};
    if(left <= start && right >= end) return {oddt[node], event[node]};
    int mid = (start+end)/2;
    p a = intervalMinMax(node*2, start, mid, left, right);
    p b = intervalMinMax(node*2+1, mid+1, end, left, right);
    // cout << min(a.first, b.first) << " " << max(a.second, b.second) << "=\n";
    return {a.first + b.first, a.second + b.second};
}

void update(int node, int start, int end, int idx, int val){
    if (idx < start || idx > end) return;
    if (end == start) {
        arr[idx] = val;
        if(arr[start]%2 == 0){
            event[node] = 1;
            oddt[node] = 0;
        }else{
            event[node] = 0;
            oddt[node] = 1;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);
    oddt[node] = oddt[node*2] + oddt[node*2+1];
    event[node] = event[node*2] + event[node*2+1];
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
        } else if(a == 2){
            p ans = intervalMinMax(1, 0, n-1, b-1, c-1);
            cout << ans.second << "\n";
        }else if (a == 3){
            p ans = intervalMinMax(1, 0, n-1, b-1, c-1);
            cout << ans.first << "\n";
        }
    }
}