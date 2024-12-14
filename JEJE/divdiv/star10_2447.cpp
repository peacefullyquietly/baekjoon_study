#include<iostream>
using namespace std;

void star(int i, int j, int num){
    if((i/num)%3==1 && (j/num)%3==1) cout << ' ';//n사이즈의 도형에서 공백 부분이라면
    else{
        if(num/3==0) cout << '*';//n사이즈이 도형에서 *부분이라면
        else star(i,j,num/3);//사이즈를 줄여 나가기
    }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int size;
    cin >> size;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            star(i,j,size);
        }
        cout << '\n';
    }
}