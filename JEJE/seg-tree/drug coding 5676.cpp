#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll tree[400001];
ll arr[100001];

ll change(ll a) {
    if (a > 0) return 1;
    else if (a < 0) return -1;
    else return 0;
}

ll init(int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    int mid = (start + end) / 2;
    return tree[node] = (init(node * 2, start, mid) * init(node * 2 + 1, mid + 1, end));
}

ll intervalMulti(int node, int start, int end, int left, int right) {
    if (start > right || end < left) return 1;
    if (start >= left && end <= right) return tree[node];
    int mid = (start + end) / 2;
    return (intervalMulti(node * 2, start, mid, left, right) * intervalMulti(node * 2 + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int idx, ll value) {
    if (start > idx || end < idx) return;
    if (end == start) {
        arr[idx] = value;
        tree[node] = value;
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, value);
    update(node * 2 + 1, mid + 1, end, idx, value);
    tree[node] = (tree[node * 2] * tree[node * 2 + 1]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n, m;
    while (cin >> n >> m) {
        memset(tree, 0, sizeof(tree));
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            arr[i] = change(arr[i]);
        }

        init(1, 0, n - 1);

        for (int i = 0; i < m; i++) {
            char a;
            int b, c;
            cin >> a >> b >> c;
            if (a == 'C') {
                update(1, 0, n - 1, b - 1, change(c));
            }
            else if (a == 'P') {
                int ans = intervalMulti(1, 0, n - 1, b - 1, c - 1);
                if (ans > 0) cout << '+';
                else if (ans < 0) cout << '-';
                else cout << '0';
            }
        }
        cout << '\n';
    }
}