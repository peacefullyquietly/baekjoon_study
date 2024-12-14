// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#define MAX 100001
using namespace std;

int arr[MAX];
int mint[MAX*4], maxt[MAX*4];

/**
 * @brief 세그트리를 처음 구성하는 함수
 * 
 * @param node
 * @param start
 * @param end
*/
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

/**
 * @brief 최솟값과 최대값이 left~right 구간에 포함되는지 확인하는 함수
 * 
 * @param node 현재 노드
 * @param start 현재 노드가 담당하는 구간의 시작
 * @param end 현재 노드가 담당하는 구간의 끝
 * @param left 구간의 시작
 * @param right 구간의 끝
*/
bool check(int node, int start, int end, int left, int right){
    if(left > end || right < start) return 1;
    if(left <= start && right >= end){
        return left <= mint[node] && right >= maxt[node];
    } else{
        int mid = (start+end)/2;
        return check(node*2, start, mid, left, right) && check(node*2+1, mid+1, end, left, right); 
    }
}

/**
 * @brief 특정 인덱스의 값을 변경하는 함수
 * 
 * @param node 현재 노드
 * @param start 현재 노드가 담당하는 구간의 시작
 * @param end 현재 노드가 담당하는 구간의 끝
 * @param idx 변경할 인덱스
 * @param val 변경할 값
*/
void update(int node, int start, int end, int idx, int val){
    if(start > idx || end < idx) return;
    if(end == start){
        mint[node] = maxt[node] = arr[start] = val;
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, val);
    update(node*2+1, mid+1, end, idx, val);
    mint[node] = min(mint[node*2], mint[node*2+1]);
    maxt[node] = max(maxt[node*2], maxt[node*2+1]);
}

/**
 * @brief arr을 기준으로 세그트리의 값을 서로 교환하는 함수
 * 
 * @param node 현재 노드
 * @param start 현재 노드가 담당하는 구간의 시작
 * @param end 현재 노드가 담당하는 구간의 끝
 * @param a 교환할 인덱스
 * @param b 교환할 인덱스
*/
void swapTree(int node, int start, int end, int a, int b){
    int tmp = arr[a];
    update(node, start, end, a, arr[b]);
    update(node, start, end, b, tmp);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, n, k;
    cin >> tc;
    while(tc--){
        cin >> n >> k;
        for(int i = 0; i < n; i++) arr[i] = i;
        init(1, 0, n-1);
        for(int i = 0; i < k; i++){
            int q, a, b;
            cin >> q >> a >> b;
            if (q){
                cout << (check(1, 0, n-1, a, b)?"YES":"NO") << '\n';
            } else {
                swapTree(1, 0, n-1, a, b);                
            }
        }
    }
}