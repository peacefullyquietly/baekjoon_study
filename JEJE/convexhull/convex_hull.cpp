// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<stack>
#include<algorithm>
#include<cstring>
#define MAX 1000
using namespace std;

typedef pair<int, int> XY;
#define x first
#define y second

int tc, N, M, u[MAX];// 루트 노드에 정보를 저장하는 유니온트리

typedef struct _Line {
    XY p1, p2;
}Line;
Line line[MAX];

int find(int n)
{
    if (u[n] < 0)return n; // 루트 노드라면
    else return u[n] = find(u[n]); // 루트 노드를 찾아야 된다면
}

void merge(int a, int b)
{
    a = find(a); //루트 노드 찾기
    b = find(b); //루트 노드 찾기
    u[a] += u[b]; // 루트 노드에 정보 더하기
    u[b] = a; // 루트 노드를 가르키기
}

int ccw(XY& a, XY& b, XY& c)
{
    int result = (a.x * b.y + b.x * c.y + c.x * a.y) - (c.x * b.y + b.x * a.y + a.x * c.y);
    if (result < 0) return -1;
    else if (result > 0) return 1;
    else return 0;
}

void _sort_point(Line& a)
{
    if (a.p2 < a.p1) swap(a.p1, a.p2);
}

bool isCross(Line& a, Line& b)
{
    int ccw1 = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2);
    int ccw2 = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);// ccw return: 1 0 -1
    if (ccw1 == 0 && ccw2 == 0) {
        _sort_point(a); _sort_point(b);
        return a.p1 <= b.p2 && b.p1 <= a.p2;
    }else if (ccw1 <= 0 && ccw2 <= 0) {
        return true;
    }else {
        return false;
    }
}

bool comp(XY& a, XY& b)
{
    
}

// void conVexHull(){
//     stack<int> s;
//     sort(line, line+tc, )
// }

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    memset(u, -1, sizeof(u));
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
    }
    for (int i = 0; i < tc; i++) for (int j = i + 1; j < tc; j++)
    {
        if (isCross(line[i], line[j]) && (find(i) != find(j)))//교차하고 같은 그룹(사이클)이 아니라면
        {
            merge(i, j);
            //cout << i << j << "a\n";
        }
    }
    int cnt = 0, maxGroup = 0;
    for (int i = 0; i < tc; i++)
    {
        if (u[i] < 0)
        {
            cnt++;
            maxGroup = max(-u[i], maxGroup);
        }
    }
    cout << cnt << "\n";
    cout << maxGroup << "\n";
}