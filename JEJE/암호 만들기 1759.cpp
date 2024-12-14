#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int a = (int)'a';
int L, C;
bool use[97];
vector<char> v;
vector<char> out;
bool check()
{
    int ja = 0, mo = 0;
    for (auto& i : out)
    {
        if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u') mo += 1;
        else ja += 1;
    }
    return (mo >= 1 && ja >= 2);
}

void hack(int cnt)
{
    if (cnt == C && check())
    {
        for (auto& i : out) cout << i;
        cout << '\n';
        return;
    }
    for (auto& j : v)
    {
        int aj = (int)j;
        if (cnt == 0 || (!use[aj - a] && out[cnt - 1] < aj))
        {
            use[aj - a] = true;
            out[cnt] = j;
            hack(cnt + 1);
            use[aj - a] = false;
            out[cnt] = 0;
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> C >> L;
    v.resize(L);
    out.resize(C);
    for (int i = 0; i < L; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    hack(0);
}