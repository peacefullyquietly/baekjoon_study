#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    if (a < 0){
        cout << (b < 0 ? 3 : 2);
    }else{
        cout << (b < 0 ? 4 : 1);
    }
}