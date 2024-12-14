#include<iostream>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        float sum = 0, avr, ta, cnt = 0;;
        cin >> ta;
        vector<int> real(ta);
        for(auto &i: real)
        {
            cin >> i;
            sum += i;
        }
        avr = sum/ta;
        for(auto &i: real)
        {
            if(i > avr) cnt += 1;
        }
        cout << fixed;
        cout.precision(3);
        cout << cnt/ta*100 << '%' <<'\n';
    }
}