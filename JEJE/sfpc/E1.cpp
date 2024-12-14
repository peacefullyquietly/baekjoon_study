#include<iostream>
using namespace std;

int n, m, k, p[101];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int i, j, t, ans = 0; cin >> n;
    for (i = 1; i <= n; i++) cin >> p[i];
    cin >> m >> k;
    k /= m;
    for (i = 1; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            for (t = j + 1; t <= n; t++) {
                if (p[i] + p[j] + p[t] <= k) ans++;
            }
        }
    }
    cout << ans;
}