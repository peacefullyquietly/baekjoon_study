#include<iostream>
#define ll long long
using namespace std;

ll tree[4000001];
ll arr[1000001];
ll ha[2][3] = {{1, 2, 3},{1, 2, 3}};

/**
 * @brief 구간합을 구하는 함수
 * 
 * @param node 현재 노드
 * @param start 현재 노드가 담당하는 구간의 시작
 * @param end 현재 노드가 담당하는 구간의 끝
 * @param left 구간합을 구하고자 하는 구간의 시작
 * @param right 구간합을 구하고자 하는 구간의 끝
 * @return ll 구간합
*/
ll intervalSum(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 0;
    if(left <= start && right >= end) return tree[node];
    int mid = (start+end)/2;
    return intervalSum(node*2, start, mid, left, right) + intervalSum(node*2+1, mid+1, end, left, right);
}

/**
 * @brief 특정 인덱스의 값을 변경하는 함수
 * 
 * @param node 현재 노드
 * @param start 현재 노드가 담당하는 구간의 시작
 * @param end 현재 노드가 담당하는 구간의 끝
 * @param index 변경하고자 하는 인덱스
 * @param value 변경하고자 하는 값
*/
void update(int node, int start, int end, int index, ll value) {
    if (index < start || index > end) return;
    if (end == start) {
        arr[index] = value;
        tree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, index, value);
    update(node * 2 + 1, mid + 1, end, index, value);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n, m, k;
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> arr[0];

    for(int i = 0; i < m; i++){
        ll a, b, c;
        cin >> a >> b >> c;
        
        if(a == 1) {
            update(1, 0, n-1, b-1, c);
        }else {
            cout << intervalSum(1, 0, n-1, b-1, c-1) << '\n';
        }
    }
}