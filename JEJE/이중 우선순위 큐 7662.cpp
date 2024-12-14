#include<iostream>
#include<vector>
#include<set>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, tc, tc2;
    char s;
    cin >> tc;
    while(tc--){
        cin >> tc2;
        multiset<int> v;
        while (tc2--)
        {
            cin >> s >> n;
            if(s=='I') v.insert(n);
            else if(!v.empty())
            {
                if(n == -1)v.erase(v.begin());
                else v.erase(--v.end());
            }
        }
        if(v.empty()) cout << "EMPTY";
        else cout << *--v.end() << ' ' << *v.begin();
        cout << '\n';
    }
}