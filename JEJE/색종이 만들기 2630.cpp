#include <iostream>

using namespace std;

int P[128][128], white, blue;

int checkBH(int x, int y, int size)
{
    int now = P[y][x];
    for (int i = y; i < y+size; i++) { //y+size<중요>
        for (int j = x; j < x+size; j++)
        {
            if (now != P[i][j]) return 2;
        }
    }
    return now;
}

void dfs(int x, int y, int size)
{
    //cout << size << '\n';//
    //cout << x << ' ' << y << "x, y\n";
    int color = checkBH(x, y, size);
    if (color == 0) {
        white += 1;
       // cout << size << ";\n";//
        return;
    }
    else if (color == 1) {
        blue += 1;
       // cout << size << ";\n";//
        return;
    }
    else {
        dfs(x, y, size / 2);
        dfs(x + size / 2, y, size / 2);//xy좌표 위치 정확히 파악 바람
        dfs(x, y + size / 2, size / 2);
        dfs(x + size / 2, y + size / 2, size / 2);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int maxS;
    cin >> maxS;
    for (int i = 0; i < maxS; i++) {
        for (int j = 0; j < maxS; j++)
        {
            cin >> P[i][j];
        }
    }
    dfs(0, 0, maxS);
    cout << white << '\n' << blue << '\n';
 }