#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    while(cin >> n)v.push_back(n);
    sort(v.begin(), v.end());
    
}