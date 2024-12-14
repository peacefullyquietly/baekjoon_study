#include<iostream>
#include<string>
#include<vector>
using namespace std;
const int MAX = 50;
int large = 0, n;

void check(vector<string>v){
    int go = 1;
    for (int y = 0; y < n; y++) {
        for (int x = 1; x < n; x++)
        {
            if (v[y][x] == v[y][x-1]) go += 1;
            else if (v[y][x] != v[y][x-1])
            {
                if (go > large)large = go;
                go = 1;
            }
        }
        if (go >= large)large = go;
        go = 1;
    }
    go = 1;
    for (int x = 0; x < n; x++) {
        for (int y = 1; y < n; y++)
        {
            if (v[y][x] == v[y-1][x]) go += 1;
            else if (v[y][x] != v[y-1][x])
            {
                if (go > large)large = go;
                go = 1;
            }
        }
        if (go >= large)large = go;
        go = 1;
    }
    return;
}
void swap_side(vector<string>v)
{
    for (int y = 0; y < n; y++) {
        for (int x = 1; x < n; x++)
        {
            swap(v[y][x - 1], v[y][x]);
            check(v);
            swap(v[y][x - 1], v[y][x]);
        }
    }
    return;
}
void swap_updown(vector<string>v)
{
    for (int x = 0; x < n; x++) {
        for (int y = 1; y < n; y++)
        {
            swap(v[y - 1][x], v[y][x]);
            check(v);
            swap(v[y - 1][x], v[y][x]);
        }
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string word;
    cin >> n;
    cin.ignore();
    vector<string> v(n);
    for (auto& i : v) {
        cin >> i;
    }
    swap_side(v);
    swap_updown(v);
    cout << large << '\n';
    return 0;

}
//5
//LLLLR
//LLLCR
//CCCLR
//RLLLC
//LLLLR