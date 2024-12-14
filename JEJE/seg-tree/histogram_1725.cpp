#include<bits/stdc++.h>
#define p pair<int,int>
#define MAX 1000000001
using namespace std;

int arr[100001], n;
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
    return {min(a.first, b.first), max(a.second, b.second)};
}

// void update(int node, int start, int end, int idx, int val){
//     if (idx < start || idx > end) return;
//     if (end == start) {
//         arr[idx] = val;
//         mint[node].first = maxt[node].first = val;
//         return;
//     }
//     int mid = (start+end)/2;
//     update(node*2, start, mid, idx, val);
//     update(node*2+1, mid+1, end, idx, val);
//     mint[node] = min(mint[node*2], mint[node*2+1]);
//     maxt[node] = max(maxt[node*2], maxt[node*2+1]);
// }

int solve(int start, int end){
    pair<p, p> minmax = intervalMinMax(1, 0, n-1, start, end);
    int ret = minmax.first.first * (end-start+1);
    if(minmax.first.second != start)
        ret = max(ret, solve(start, minmax.first.second-1));
    if(minmax.first.second != end)
        ret = max(ret, solve(minmax.first.second+1, end));
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    init(1, 0, n-1);

    cout << solve(0, n-1);
}