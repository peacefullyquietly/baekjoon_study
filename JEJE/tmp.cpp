#include <stdio.h>

void printarr(int val,int j){
    printf("%d",val);
    if(j==4) printf("\n");
}

void into(int arr[],int i,int j){
    arr[j]=i;
    printarr(arr[j],j);
}

int main() {
    int arr[5]={0,1,2,3,4};
    for(int i=1;i<=5;i++){
        for(int j=0;j<5;j++){
            into(arr,(j+1)*i%5,j);
        }
    }
}
