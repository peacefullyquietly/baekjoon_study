#include<iostream>
using namespace std;

int v[65][65];

int check(int x, int y, int s)
{
    int num = v[y][x];
    for(int i = y; i < y+s; i++){
        for(int j = x; j < x+s; j++){
            if(v[i][j] != num) return 2;
        }
    }
    return num;
}

void QuadTree(int x, int y, int s)
{
    int result = check(x, y, s);
    if(result != 2){
        cout << result;
        return;
    }else{
        cout << '(';
        QuadTree(x,y,s/2);
        QuadTree(x+s/2,y,s/2);
        QuadTree(x,y+s/2,s/2);
        QuadTree(x+s/2,y+s/2,s/2);
        cout << ')';
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int s;
    char num;
    cin >> s;
    for(int i = 0; i < s; i++){
        for(int j = 0; j < s; j++){
            cin >> num;
            v[i][j] = num-'0';
        }
    }
    QuadTree(0,0,s);
    cout << '\n';
}