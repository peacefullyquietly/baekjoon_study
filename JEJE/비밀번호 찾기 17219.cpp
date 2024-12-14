#include<map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    map<string,string> v;
    int tc, tc2;
    cin >> tc >> tc2;
    string s;
    while(tc--)
    {
        cin >> s;
        cin >> v[s];
    }
    while(tc2--)
    {
        cin >> s;
        cout << v[s] << '\n';
    }
    return 0;
}