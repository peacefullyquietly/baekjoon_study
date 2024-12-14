#include<iostream>
#include<vector>
using namespace std;
const int MAX = 1000000;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    vector<unsigned long> v(MAX + 1, 1);
    for (int i = 2; i <= MAX; i++) {
        for (int j = 1; j * i < MAX; j++)
        {
            v[i * j] += i;
        }
    }
    for (int i = 1; i < MAX + 1; i++) v[i] += v[i - 1];
    while (cin >> n) cout << v[n] << '\n';

}