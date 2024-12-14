#include<bits/stdc++.h>
#define MAX 1000001
using namespace std;

int tree[MAX*4];

void update(int node, int start, int end, int idx, int chg){
    if(idx < start || idx > end) return;
    if(start == end){
        tree[node] += chg;
        return;
    }
    int mid = (start+end)/2;
    update(node*2, start, mid, idx, chg);
    update(node*2+1, mid+1, end, idx, chg);
    tree[node] = tree[node*2] + tree[node*2+1];
}

int getCandy(int node, int start, int end, int want){
    if(start == end) return start;
    int mid = (start+end)/2;
    if(want <= tree[node*2]) return getCandy(node*2, start, mid, want);
    else return getCandy(node*2+1, mid+1, end, want-tree[node*2]);
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int query;
    cin >> query;

    int order, b, c;
    while(query--){
        cin >> order;
        if(order == 1){
            cin >> b;
            int ans_idx = getCandy(1,1,MAX,b);
            cout << ans_idx << '\n';
            update(1,1,MAX,ans_idx,-1);
        } else {
            cin >> b >> c;
            update(1,1,MAX,b,c);
        }
    }
}