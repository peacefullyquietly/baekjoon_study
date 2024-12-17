// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<cstring>
#define MAX 2
using namespace std;

typedef long long ll;
typedef pair<ll, ll> XY;
#define x first
#define y second

typedef struct _Line {
    XY p1, p2;
}Line;
Line line[MAX];

int ccw(XY& a, XY& b, XY& c)
{
    ll result = (a.x * b.y + b.x * c.y + c.x * a.y) - (c.x * b.y + b.x * a.y + a.x * c.y);
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
    int ccw1 = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2), ccw2 = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);// ccw return: 1 0 -1
    if (ccw1 <= 0 && ccw2 <= 0) {
        if (ccw1 == 0 && ccw2 == 0) {
            _sort_point(a); _sort_point(b);
            return a.p1 <= b.p2 && b.p1 <= a.p2;
        }else {
            return true;
        }
    }else {
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 2; i++)
    {
        cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
    }
    cout << isCross(line[0], line[1]) << "\n";
}