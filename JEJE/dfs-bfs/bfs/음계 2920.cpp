#include<iostream>
#include<vector>
using namespace std;

int check(vector<int> &v)
{
    bool c = false;
    for(int i = 1; i < 8; i++)
    {
        if(v[i-1] < v[i]) c = true;
        else
        {
            c=false;
            break;
        }
    }if(c) return 1;
    
    for(int i = 1; i < 8; i++)
    {
        if(v[i-1] > v[i]) c = true;
        else
        {
            c=false;
            break;
        }
    }if(c) return 2;
     else return 3;
}

int main()
{
    vector<int> v(8);
    for(auto &i : v) cin >> i;
    int flag = check(v);
    if(flag == 1) cout << "ascending";
    else if(flag == 2) cout << "descending";
    else cout << "mixed";
    cout << '\n';   
}