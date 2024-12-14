#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define MAX 501

using namespace std;

int N, M, S, D;
vector<int> ben[MAX];
typedef struct _Info {
    int v, w;
    bool isBen;
    bool operator<(const _Info& a)const {
        return w > a.w;
    }
}Info;
vector<Info> list[MAX];

int dijkstra() {
    int dist[MAX];
    memset(dist, 0x3f, sizeof(dist));
    priority_queue<Info> pq;
    pq.push({ S, 0, false });
    dist[S] = 0;
    while (!pq.empty()) {
        int cur = pq.top().v, w = pq.top().w;
        pq.pop();
        if (dist[cur] < w) continue;
        for (auto& i : list[cur]) {
            int next = i.v, add = i.w, isBen = i.isBen;
            if (isBen) continue;
            if (dist[next] > dist[cur] + add) {
                ben[next].clear();
                ben[next].push_back(cur);
                dist[next] = dist[cur] + add;
                pq.push({ next, dist[cur] + add, false });
            }
            else if (dist[next] == dist[cur] + add) {
                ben[next].push_back(cur);
            }
        }
    }
    return dist[D];
}

void rmv_vertax() {
    queue<int> q;
    bool visited[MAX] = { false, };
    q.push(D);
    visited[D] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (auto& i : ben[node]) {
            for (auto& j : list[i]) {
                if (node == j.v) j.isBen = true;
            }
            if (!visited[i]) q.push(i);
            visited[i] = true;
        }
    }
}


void init() {
    for (int i = 0; i < N; i++) {
        list[i].clear();
        ben[i].clear();
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

    int INF, _INF[1];
    memset(_INF, 0x3f, sizeof(_INF));
    INF = _INF[0];

    while (true) {
        cin >> N >> M;

        if (N == 0 && M == 0) break;

        cin >> S >> D;
        for (int i = 0; i < M; i++) {
            int U, V, P;
            cin >> U >> V >> P;
            list[U].push_back({ V, P, false });
        }

        dijkstra();
        rmv_vertax();
        int ans = dijkstra();

        cout << (ans == INF ? -1 : ans) << '\n';

        init();
    }
}