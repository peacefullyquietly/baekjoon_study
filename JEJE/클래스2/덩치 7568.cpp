#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<pair<int,int>> v;
    int tc;
    cin >> tc;
    v.resize(tc);
    for(auto &i : v)cin >> i.first >> i.second;
    for(auto &i : v){
        int k = 1;
        for(auto &j : v)
        {
            if(j.first > i.first && j.second > i.second)k+=1;
        }
        cout << k << ' ';
    }
    cout << '\n';
}