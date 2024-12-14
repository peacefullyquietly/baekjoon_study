#include<iostream>
using namespace std;
const int MAX = 101, INF = 1000000000;
int v[MAX][MAX];

void c()
{
    for(auto &i : v){
        for(auto &j : i){
            j = INF;
        }
    }
    for(int i = 0; i < MAX; i++)
    {
        v[i][i] = 0;
        v[i][0] = 0;
        v[0][i] = 0;
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int city, bus;
    cin >> city >> bus;
    c();
    while(bus--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        if(v[a][b] > w)v[a][b] = w;
    }

    for(int k = 1; k <= city; k++){
        for(int i = 1; i <= city; i++){
            for(int j = 1; j <= city; j++){
                //if(v[i][j] == INF || v[i][k] == INF) continue;
                v[i][j] = min(v[i][j],v[i][k]+v[k][j]);
            }
        }
    }

    for(int i = 1; i <= city; i++){
        for(int j = 1; j <= city; j++){
            if(v[i][j] == INF) cout << "0 ";
            else cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
}