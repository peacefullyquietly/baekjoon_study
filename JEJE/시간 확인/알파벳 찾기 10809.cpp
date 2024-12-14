#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    map<char,int> m;
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
    {
        if(m.find(s[i]) == m.end())
        {
            m[s[i]] = i;
        }
    }
    string abc = "abcdefghijklmnopqrstuvwxyz";
    for(auto &i : abc)
    {
        if(m.find(i) != m.end())cout << m[i];
        else cout << -1;
        cout << ' ';
    }
    cout << '\n';
}