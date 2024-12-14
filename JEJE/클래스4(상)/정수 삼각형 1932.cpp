#include<iostream>
using namespace std;

const int MAX = 501;
int arr[MAX][MAX], dp[MAX][MAX];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int size;
    cin >> size;
    for(int i = 1; i <= size; i++){
        for(int j = 1; j <= i; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = size; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            arr[i-1][j] += max(arr[i][j],arr[i][j+1]); 
        }
    }
    cout << arr[1][1] << '\n';
}