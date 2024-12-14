// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <bits/stdc++.h>
using namespace std;

typedef struct _Info {
    int o, r;
}Info;

vector<Info> v;
unordered_map<int, int> m;

bool cmp(const Info& a, const Info& b) {
    if(a.o - a.r == b.o - b.r) return a.r > b.r;
    else return a.o - a.r < b.o - b.r;
}

int left(int i) {
    return v[i].o - v[i].r;
}

int right(int i) {
    return v[i].o + v[i].r;
}


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, i, ans = 1;
    
    cin >> n;
    v.resize(n);
    for (auto& i : v){
        cin >> i.o >> i.r;
    }
    sort(v.begin(), v.end(), cmp);

    for (i = 0; i < n; i++) {
        ans++;
        if (!m.count(left(i)) && !m.count(right(i))) {
            m[left(i)] = i+1;
            m[right(i)] = i+1;
        }else{
            if (!m.count(left(i)) && m.count(right(i))) {
                m[left(i)] = m[right(i)];
            }else if (m.count(left(i)) && !m.count(right(i))) {
                m[right(i)] = m[left(i)];
            }else if (m[left(i)] != m[right(i)]) {
                m[left(i)] = m[right(i)];
            }else if (m[left(i)] == m[right(i)]) {
                ans++;
            }
        }
        
    }
    cout << ans << '\n';
}