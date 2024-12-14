#include<iostream>
#include<cstring>
using namespace std;

int v[101][101];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc, n;
    cin >> tc;
    //for(int i = 0; i < tc; i++) memset(v[i], 10, sizeof v[i]);
    for(int i = 0; i < tc; i++){
        for(int j = 0; j < tc; j++){
            cin >> v[i][j];
        }
    }
    for(int k = 0; k < tc; k++){
        for(int i = 0; i < tc; i++){
            for(int j = 0; j < tc; j++){
                if(v[i][k] && v[k][j]) v[i][j] = 1;
            }
        }
    }
    for(int i = 0; i < tc; i++){
        for(int j = 0; j < tc; j++){
            if(v[i][j] > 0) cout << 1;
            else cout << 0;
            cout << ' ';
        }
        cout << '\n';
    }
}