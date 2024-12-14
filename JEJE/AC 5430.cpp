#include<iostream>
#include<deque>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
deque<int> input(string list, int size)
{
    deque<int>v;
    vector<int> num;
    for(int i = 0; i < list.size(); i++)
    {
        if(list[i] != '[')
        {
            if(list[i] == ',' || i == list.size()-1){
                int rn = 0;
                for(auto j : num) rn = rn*10+j;
                if(rn != 0)v.push_back(rn);
                num.clear();
            }else{
                num.push_back((int)list[i]-'0');
            }
        }
    }
    return v;
}

void print(deque<int> v, bool error)
{
    if(!error)
    {
        cout << '[';
        for(int i = 0; i<v.size(); i++)
        {
            cout << v[i];
            if(i != v.size()-1) cout << ',';
        }
        cout << ']';
    }else cout << "error";
    cout << '\n';
}

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        bool error = false;
        int size, r = 0;
        string order, list;
        cin >> order >> size >> list;
        deque<int>v = input(list, size);
    
        for(auto& i : order)
        {
            if (i == 'R')
            {
                r += 1;
            }
            else if('D')
            {
                if(!v.empty()){
                    if(r%2 != 0) v.pop_back();
                    else v.pop_front();
                }else{
                    error = true;
                    break;
                }
            }
        }
        if(r%2 != 0) reverse(v.begin(), v.end());
        print(v, error);
    }
}