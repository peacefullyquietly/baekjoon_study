#include<stdio.h>

int arr[10];

int main() {
    
    int n;
    scanf("%d", &n);
    
    while (n > 0) {
        arr[n % 10]++;
        n /= 10;
    }

    arr[6] = (arr[6] + arr[9] + 1) / 2;
    arr[9] = 0;

    int ans = 0;
    for (int i = 0; i < 10; i++) {
        ans = (ans < arr[i] ? arr[i] : ans);
    }

    printf("%d", ans);
}