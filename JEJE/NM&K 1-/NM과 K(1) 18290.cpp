#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> input(10, vector<int>(10));
bool use[11][11];
int N, M, K;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int answer = -2147483647;

bool check_can_go(int x, int y)
{
    for (int i = 0; i < 4; i++)//4번 반복
    {
        int nx = x + dx[i]; //x축 이동하기
        int ny = y + dy[i]; //y축 이동하기(당연히 0이면 안움직임)
        if (nx >= 0 && nx < N && //x범위를 벗어 나지 않고
            ny >= 0 && ny < M && //y범위를 벗어 나지 않는다면
            use[nx][ny]) //내가 원하는 조건을 탐색함
        {
            return false;
        }
    }
    return true;
}

void bestSum(int cnt, int sum)
{
    //cout << sum <<'\n';
    if (cnt == K)
    {
        answer = max(answer, sum);
        return;
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (check_can_go(i, j) && !use[i][j])
            {
                use[i][j] = true;
                bestSum(cnt+1, input[i][j] + sum);
                use[i][j] = false;
            }
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int dum;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++)
        {
            cin >> dum;
            input[i][j] = dum;
        }
    }
    bestSum(0, 0);
    cout << answer << '\n';
    return 0;
}