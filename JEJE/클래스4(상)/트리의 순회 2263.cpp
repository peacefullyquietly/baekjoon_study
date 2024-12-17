// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include<iostream>
#include<vector>
using namespace std;

const int MAX = 100001;
int inorder[MAX], postorder[MAX], Index[MAX];

void getPreorder(int inS, int inE, int posS, int posE)
{
    //pos 오더 = 루트값 찾기용
    //in 오더 = 루트의 위치를 기반으로 트리의 오른쪽 왼쪽을 구분함


    if(inS > inE || posS > posE) return; // 시작 지점이 마자막 지점보다 커지면 종료
    int rootIndex = Index[postorder[posE]]; //루트 지점의 인덱스 값 = 포스트 오더 마지막 값의 인덱스값
    int leftS = rootIndex - inS; // 왼쪽 재귀부분 사이즈 = 루트의 인덱스 - 인오더 시작점;
    //int rightS = inE - rootIndex;
    cout << inorder[rootIndex] << ' ';
    
    getPreorder(inS, rootIndex-1, posS, posS + leftS - 1);
    //왼쪽 부분 재귀
    /*
    인오더(루트를 기준으로 왼쪽 오른쪽의 값을 알수 있게해줌):
    |<- 인오더 시작점                   루트의 인덱스-1 ->|
    포스트오더(루트의 값을 알려줌(항상 마지막 값이 루트값임)):
    |<- 포스오더 시작점        포스오더 시작점+왼쪽 재귀 부분 사이즈-1 ->|
    */
    
    //===================================================================
    
    getPreorder(rootIndex+1, inE, posS + leftS, posE - 1);
    //오른쪽 부분 재귀
    /*
    인오더(루트를 기준으로 왼쪽 오른쪽의 값을 알수 있게해줌):
    |<- 루트의 인덱스+1                   인오더 마지막 지점 ->|
    포스트오더(루트의 값을 알려줌(항상 마지막 값이 루트값임)):
    |<- 포스오더 시작점 + 왼쪽 재귀 부분 사이즈+1      포스오더 마지막 지점 ->|
    */
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        cin >> inorder[i];
        Index[inorder[i]] = i; //인오더에서 입력 받은 값의 인덱스의(=위치) 값
    }for(int i = 0; i < tc; i++){
        cin >> postorder[i];
    }
    getPreorder(0,tc-1,0,tc-1);
}