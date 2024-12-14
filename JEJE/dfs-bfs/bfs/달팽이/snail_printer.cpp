#include<iostream>
using namespace std;

int dy[] = {0,1,0,-1}; // 시계 방향으로 탐색
int dx[] = {1,0,-1,0}; // 하는 방향 배열
int scale, map[2000][2000]; //달팽이의 사이즈와 0으로 초기화된 달팽이 배열

struct Info
{
    int x, y, cnt; //내가 방문할 x좌표, y좌표와 내가 방문할 곳에 입력할 값
};


void snail()
{
    Info num = {0, 0, 0};// map 배열의 (0,0)좌표값의 값은 0
    while (true)
    {
        for(int i = 0; i < 4; i++) // 방향 배열 업데이트
        {
            for(int j = 1; j < scale; j++) // 달팽이 크기 이상 방문할수 없으므로(이 포문 덕분에 사이즈를 넘었는지 밑에서 따로 체크하지 않아도 된다)
            {
                int x = num.x, y = num.y, cnt = num.cnt; //원할한 사용을 위해 구조체 풀어 놓기(= bfs와 비슷하게 사용)
                map[y][x] = cnt; // map 배열의 (x,y)좌표값의 값을 cnt로
                if(num.cnt == scale*scale-1) return; //만약 다채웠으면 함수 종료
                int cx = x+dx[i]; // 다음 차례에 방문할
                int cy = y+dy[i]; // x,y 좌표 구하기
                if(map[cy][cx] > 0 || (cnt > 0 && cx == 0 && cy == 0)){ //만약 방문했거나 원점 좌표(시작 값이 0이라면 이것이 시작 값인지, 방문하지 않아서 0인지 구분되지 않으므로) 라면
                    break; //포문 종료해 일단 방향 배열 업데이트 하러가기
                }else{ // 만약 방문하지 않은 상태라면
                    num = {cx, cy, cnt+1}; //x, y, cnt값 업데이트 하기
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> scale;
    snail();
    for(int i = 0; i < scale; i++){
        for(int j = 0; j < scale; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << "\n";
    }
}