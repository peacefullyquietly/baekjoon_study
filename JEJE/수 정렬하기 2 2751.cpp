#include<iostream>
#include<set>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    set<int> v;
    cin >> n;
    while(cin >> n) v.insert(n);
    for(auto &i : v) cout << i << '\n';
}