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

typedef struct _Cross{
    double x, y;
    bool can = false;
}Cross;
Cross cro;

int ccw(XY& a, XY& b, XY& c)
{
    ll result = (a.x * b.y + b.x * c.y + c.x * a.y) - (c.x * b.y + b.x * a.y + a.x * c.y);
    if (result < 0) return -1;
    else if (result > 0) return 1;
    else return 0;
}

void crossPoint(Line& p12, Line&p23)
{
    XY& a = p12.p1, b = p12.p2, c = p23.p1, d = p23.p2;
    double px = (a.x * b.y - a.y * b.x) * (c.x - d.x) - (a.x - b.x) * (c.x * d.y - c.y * d.x);
	double py = (a.x * b.y - a.y * b.x) * (c.y - d.y) - (a.y - b.y) * (c.x * d.y - c.y * d.x);
	double p = (a.x - b.x) * (c.y - d.y) - (a.y - b.y) * (c.x - d.x);
    if(p == 0){
        if(b == c && a < c){
            cro.can = true;
            cro.x = b.x;
            cro.y = b.y;
        }else if(a == d && c < a){
            cro.can = true;
            cro.x = a.x;
            cro.y = a.y;
        }
    }else{
        cro.can = true;
        cro.x = px/p;
        cro.y = py/p;
    }
}

void _sort_point(Line& a)
{
    if (a.p2 < a.p1) swap(a.p1, a.p2);
}

bool isCross(Line& a, Line& b)
{
    int ccw1 = ccw(a.p1, a.p2, b.p1) * ccw(a.p1, a.p2, b.p2), ccw2 = ccw(b.p1, b.p2, a.p1) * ccw(b.p1, b.p2, a.p2);// ccw return: 1 0 -1
    if (ccw1 == 0 && ccw2 == 0) {
        _sort_point(a); _sort_point(b);
        return a.p1 <= b.p2 && b.p1 <= a.p2;
    }else if (ccw1 <= 0 && ccw2 <= 0) {
        return true;
    }else {
        return false;
    }
}


int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i = 0; i < 2; i++) cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
    
    if(isCross(line[0], line[1])){
        cout << true << '\n';
        crossPoint(line[0], line[1]);
    }else{
        cout << false << '\n';
    }
    
    if(cro.can)
    {
        cout << fixed;
        cout.precision(9);
        cout << cro.x << ' ' << cro.y << '\n';
    }
}