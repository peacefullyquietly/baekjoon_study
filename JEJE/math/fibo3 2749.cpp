#include<iostream>
#include<fstream>

#define long long long
using namespace std;

long holy_fibo_arr[1500001];

void init(){

    holy_fibo_arr[0] = 0;
    holy_fibo_arr[1] = 1;
    for(int i = 2; i <= 1500000; i++){
        holy_fibo_arr[i] = (holy_fibo_arr[i-1] + holy_fibo_arr[i-2])%1000000;
    }

    // curious huh?
    // ofstream writeFile;
    // writeFile.open("holy_fibo_arr.txt");
    // for(int i = 0; i <= 1500000; i++){
    //     writeFile << holy_fibo_arr[i] << ',';
    // }
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    init();
    long n;
    cin >> n;
    cout << holy_fibo_arr[n%1500000] << '\n';
}