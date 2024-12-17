// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <iostream>
#include <vector>
using namespace std;
bool use[9];//벡터에 존자하는 숫자 존제 = true, 없음 = false
vector<int> v;
int n, m;
//재귀함수에 사용하기 위해 전역변수 선언

void nm()//for문 끝까지 돌고 알아서 멈출거라는 상남자식 void선언
{
    if (v.size() == m)//만약 사이즈가 가득 찬다면
    {
        vector<int>::iterator out;
        for (out = v.begin(); out != v.end(); out++)
        {
            cout << *out << " "; //출력
        }
        cout << "\n";
        //void 아니면 대충 이쯤 가독성을 위해 리턴이 위치
    }
    for (int i = 1; i <= n; i++) //n만큼 숫자를 찔러 넣어 보기 <2>
    {
        if (!use[i])//현재 벡터에 존제하지 않는 값이라면 <3> //이거때문에 가득 찬경우 출력 if문을 들어간뒤에도 for문이 무시되고 함수가 종료될수가 있음
        {
            v.push_back(i);//벡터의 뒤쪽에 추가 4
            use[i] = true;//숫자가 존제함을 알림 5
            nm();//이제 다음 숫자를 넣으러 여정을 떠남 1
            //1~5 반복하다가 맨 위쪽에 있는 if문에 걸린다면
            v.pop_back();//트리의 끝까지 와서 위의 재귀까 끝나면 이제 뒤에서 하나를 제거함
            use[i] = false; //제거한거는 벡터에 존제하지 않으므로 false로 변환
        }
    }
    // return ~~~; (void라 필요 없음)
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    nm();
}