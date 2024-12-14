#include<iostream>
#include<vector>
using namespace std;
const int MAX = 1000000;
bool used[MAX+1];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    unsigned long a, b;
    used[0] = used[1] = true ; 
    for(int i = 2; i*i <= MAX; i++){
        if(!used[i])
        {
            for(int j = 2*i; j <= MAX; j += i) used[j] = true;
        }
    }

    cin >> a >> b;
    for(unsigned long i = a; i <= b; i++)
    {
        if(!used[i]) cout << i << '\n';
    }
    
}