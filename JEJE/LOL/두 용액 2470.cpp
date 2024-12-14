#include<iostream>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

typedef pair<int, int> p;

p twoP(vector<int>& v)
{
    int flag = 2000000001; //두 값의 합중 가장 작은 값을 저장
    int first = 0, last = v.size()-1, sum; //포인터와 순간 합
    p index; //두 값의 인덱스를 저장
    while(first < last)
    {
        sum = v[first] + v[last];
        if(abs(sum) < flag)
        {
            flag = abs(sum);
            index = {first, last};
            if(flag == 0) break;
        } 
        if(sum < 0){
            first++;
        }else{
            last--;
        }
    }
    return index;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc;
    vector<int> v;

    cin >> tc;
    v.resize(tc);
    for(int i = 0; i < tc; i++) cin >> v[i];
    sort(v.begin(), v.end());
    p ans = twoP(v);
    cout << v[ans.first] << ' ' << v[ans.second] << '\n';
}