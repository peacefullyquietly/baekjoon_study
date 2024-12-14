#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
 
#define MAXSIZE 1000001
 
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
 
int n, m, k;
ll arr[MAXSIZE], segtree[MAXSIZE * 4], lazy[MAXSIZE * 4];
 
void create_segtree(int node, int start, int end) {
    if (start == end) {
        //리프 노드인 경우
        segtree[node] = arr[start];
        return;
    }
    int mid = (start + end) / 2;
    create_segtree(node * 2, start, mid);
    create_segtree(node * 2 + 1, mid + 1, end);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}
 
void update_lazy(int node, int start, int end) {
    //현재 노드의 lazy값을 반영함
    if (lazy[node] != 0) {
        segtree[node] += ((ll)end - start + 1) * lazy[node];        //구간의 크기만큼 반영
        if (start != end) {
            //구간 노드라면, 양쪽 자식에 lazy값을 물려줌
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;        //초기화
    }
}
 
void update_range(int node, int start, int end, int l, int r, ll val) {
    //구간 갱신 함수
    update_lazy(node, start, end);        //방문하는 노드에 대해 lazy 값이 있다면 반영
 
    if (l > end || r < start) return;        //포함되지 않는 범위
 
    //완전히 포함되는 범위
    if (l <= start && end <= r) {
        segtree[node] += ((ll)end - start + 1) * val;    //구간의 크기만큼 '현재 노드에만' 반영
        if (start != end) {
            //구간 노드라면, 양쪽 자식에 lazy값을 추가
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }
 
    //걸치는 범위
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, l, r, val);
    update_range(node * 2 + 1, mid + 1, end, l, r, val);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}
 
ll query(int node, int start, int end, int l, int r) {
    //구간 쿼리 함수
    update_lazy(node, start, end);        //방문하는 노드에 대해 lazy 값이 있다면 반영
 
    if (l > end || r < start) return 0;        //포함되지 않는 범위
 
    //완전히 포함되는 범위
    if (l <= start && end <= r) return segtree[node];
 
    //걸치는 범위
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}
 
void init() {
    cin >> n >> m >> k;
 
    for (int i = 1; i <= n; i++) cin >> arr[i];
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(NULL);
 
    init();
    create_segtree(1, 1, n);
 
    int t, f, s, v;
    int udt = 0, qry = 0;
    while(1){
        if (udt == m && qry == k) break;
        cin >> t >> f >> s;
        if (t == 1) {
            cin >> v;
            update_range(1, 1, n, f, s, v);
            udt++;
        }
        else {
            printf("%lld\n", query(1, 1, n, f, s));
            qry++;
        }
    }
 
    return 0;
}
