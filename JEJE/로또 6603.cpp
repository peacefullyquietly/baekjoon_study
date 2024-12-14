#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> out(6);
vector<int> v;
int K;
void finder(int start, int count)
{
    if (count == 6)
    {
        for (auto& i : out)
        {
            cout << i << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < K; i++)
    {
        out[count] = v[i];
        finder(start+1, count+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1)
    {
        cin >> K;
        if (K == 0) break;
        for (int i = 0; i < K; i++)
        {
            int num;
            cin >> num;
            v.push_back(num);
        }
        finder(0, 0);
        v = {};
        cout << '\n';
    }
}