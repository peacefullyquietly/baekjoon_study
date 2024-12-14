#include<iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc, v[10000] = {0};
    cin >> tc;
    for (int i = 0; i < tc; i++)
    {
        int n;
        cin >> n;
        v[n-1] += 1;
    }
    
    for(int i = 0; i < 10000; i++){
        for(int j = 0; j < v[i]; j++)
        {
            if(v[i] != 0)
            {
                cout << i+1 << '\n';
            }
        }
    }
}