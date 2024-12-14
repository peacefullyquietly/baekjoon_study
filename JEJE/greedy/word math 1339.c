// SPDX-License-Identifier: AGPL-3.0-or-later
// NOTICE: This code is restricted from being used for any AI or machine learning training purposes.
#include <stdio.h>
#include <string.h>

#define MAXN 10000 // 최대 단어 개수

char words[MAXN][21]; // 단어 배열
int word_cnt[27];
int pow_arr[] = {0, 1, (int)1e1, (int)1e2, (int)1e3, (int)1e4, (int)1e5, (int)1e6, (int)1e7, (int)1e8, (int)1e9};

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n;
    
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", words[i]);
    }

    for (int i = 0; i < n; i++) {
        int j = strlen(words[i]);
        for (int k = 0; k < j; k++) {
            word_cnt[words[i][k] - 'A'] += pow_arr[j - k];
        }
    }

    qsort(word_cnt, 27, sizeof(int), compare);

    int ans = 0, flag = 9;
    for (int i = 0; i < 27; i++) {
        if (word_cnt[i] == 0) break;
        ans += (flag-- * word_cnt[i]);
    }

    printf("%d\n", ans);

    return 0;
}