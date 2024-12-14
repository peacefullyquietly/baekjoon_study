// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;

int v[51][51];

int black(int x, int y)
{//검정으로 시작(검정 = 짝수 좌표)
    int cnt = 0;
    for(int i = y; i < y+8; i++){
        for(int j = x; j < x+8; j++){
            if((j % 2 == 0 && i % 2 == 0) ||
            (j % 2 != 0 && i % 2 != 0)){//만약 오직 짝수 or 홀수 좌표일경우
                if(v[i][j] != 1) cnt += 1; //검정색이 아니라면
            }else{//만약 홀수 
                if(v[i][j] != 0) cnt += 1; //흰색이 아니라면
            }
        }
    }
    return cnt;
}
/*
짝짝/홀짝/짝짝 101
짝홀/홀홀/짝홀 010
짝짝/홀짝/짝짝 101
*/
int white(int x, int y)
{//흰색으로 시작(흰색 = 짝수 좌표)
    int cnt = 0;
    for(int i = y; i < y+8; i++){
        for(int j = x; j < x+8; j++){
            if((j % 2 == 0 && i % 2 == 0) ||
            (j % 2 != 0 && i % 2 != 0)){//만약 오직 짝수 or 홀수 좌표일경우
                if(v[i][j] != 0) cnt += 1; //흰색이 아니라면
            }else{//만약 홀수 
                if(v[i][j] != 1) cnt += 1; //검정색이 아니라면
            }
        }
    }
    return cnt;
}



int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int N, M, answer = 50*50*64*10;
    cin >> N >> M;
    char WB;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> WB;
            if(WB == 'B')v[i][j] = 1;
            else v[i][j] = 0;
        }
    }

    for(int i = 0; i < N-7; i++){
        for(int j = 0; j < M-7; j++){
            answer = min(answer, min(black(j,i),white(j,i)));
        }
    }
    cout << answer << '\n';
}