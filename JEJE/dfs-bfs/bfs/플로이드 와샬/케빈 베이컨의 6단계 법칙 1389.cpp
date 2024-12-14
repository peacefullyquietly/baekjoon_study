#include<iostream>
#include<cstring>
using namespace std;
const int MAX = 300000000;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int v[101][101];
    pair<int,int> bacon[101], answer = {MAX,MAX};
    int U, R;

    //초기화
    for(int i = 0; i<101; i++) memset(v[i], 10, sizeof v[i]); // 플로이드 와샬을 통해 최솟값을 구해야 하므로 배열을 기본적으로 어마무시하게 만듬
    for(int i = 1; i<101; i++)v[i][i] = 0; // x=y인 지점은 플로이드 와샬에 영향이 없도록 0으로 바꿈
    bacon[0] = {MAX,MAX}; //1.케빈베이컨수, 2.친구번호가 우선순위이므로 이를 간단하게 하기 위해 pair를 통해 비교함

    cin >> U >> R;//유저의 수와 관계
    while(R--)
    {
        int a, b;
        cin >> a >> b;
        v[a][b] = 1;
        v[b][a] = 1;
        //인접행렬을 입력을 받아 만듬
    }
    //이곳에서 말하는 케빈 베이컨수는 한사람이 다른 사람에게 갈때까지 걸리는 단계를 말하며
    //진짜 케빈 베이컨수는 한사람이 가지는 케빈 베이컨수의 합이라고 하였습니다.
    for(int k = 1; k <= U; k++){//중간에 거칠 노드
        for(int i = 1; i <= U; i++){//시작노드
            for(int j = 1; j <= U; j++)//도착 노드
            {
                v[i][j] = min(v[i][j], v[i][k]+v[k][j]);
                //노드의 가중치 = 기존에 가지고 있던 가중치 or 다른노드를(i -> k -> j)거친 가중치중 가장 작은수
                //이렇게 하면 기존에 갈수 없던 노드에 대해서도 추적할수 있음
                //그리고 그렇게 구한 값들중 가장 작은 값을 저장하면 i -> j로 가는 가장 짧은 경로를 구할수 있게됨,

                //베이컨 수는 사람하나를 건널때마다 1씩 커지므로 가중치가  1이라고 할수 있음
                //따라서 노드를 건널때마다 가중치가 자연스럽게 더해지는데 j에 대한 케빈 베이컨수와 일치함
                //근데 위의 알고리즘은 i가 j에게 도달할수 있는 경우의 수중 케빈 베이컨 수가 가장 작은, 즉 가장 가까운 사람을
                //알아서 구하기 때문에 이는 i가 j에 대해 가지는(가장 작은)케빈 베이컨 수가 됨
            }
        }
    }
    
    for(int i = 1; i <= U; i++){
        for(int j = 1; j <= U; j++)
        {
            bacon[i] = {bacon[i].first+v[i][j],i};//i가 각각의 j에 가지는 케빈 베이컨수를 전부 더해 i의 케빈 베이컨 수의 총합을 구한다.
        }
        //cout << bacon[i].first << "\n";
        answer = min(answer, bacon[i]);//조건에 맞는 수를 구한다
    }
    cout << answer.second << '\n'; //출려억
}