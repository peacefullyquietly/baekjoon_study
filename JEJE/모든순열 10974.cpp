#include<iostream>

using namespace std;
// && (cnt == 0 || i > v[cnt-1])
int n ,v[9];
bool use[9];

void view(int cnt, int start)
{
    if(cnt == n)
    {
        for(int i = 0; i<n; i++)cout << v[i] << ' ';
        cout << '\n';
    }
    for(int i = 1; i <= n; i++)
    {
        if(!use[i])
        {
            v[cnt] = i;
            use[i] = true;
            view(cnt+1, i);
            use[i] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    view(0,0);
}