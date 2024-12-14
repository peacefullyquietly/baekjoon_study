#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> v;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc; cin >> tc;
    while (tc--) {
        int pos = 0, neg = 0;

        ll n; cin >> n;
        v.clear();
        v.resize(n+1);
        cin >> v[0];
        if (n == 1){
            cout << (v[0] > 0 ? "YES" : "NO") << '\n';
            continue;
        }
        for (int i = 1; i < n-1; i++) {
            cin >> v[i];
            if(v[i-1] > 0){
                if(v[i] > 0) pos++;
                else{
                    if(v[i] + v[i-1] > 0) v[i] += v[i-1];
                    else pos++;
                }
            }else{
                if(v[i] > 0){
                    if(v[i] + v[i-1] > 0) v[i] += v[i-1];
                    else neg++;
                }else v[i] += v[i-1];
            }
        }

        cin >> v[n - 1];
        if (v[n - 2] > 0) {
            if (v[n - 1] > 0) pos += 2;
            else if (v[n - 1] + v[n - 2] > 0) pos++;
        }
        else if (v[n - 2] < 0) {
            if (v[n - 1] > 0) {
                if (v[n - 1] + v[n - 2] > 0) pos++;
            }
            else neg++;
        }

        //cout << pos << ' ' << neg << '\n';
        cout << (pos > neg ? "YES" : "NO") << '\n';
    }
}