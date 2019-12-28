/*
 *
 *  2019.12.28
 *  https://www.acmicpc.net/problem/1932
 *
*/

#include <stdio.h>

int max(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int main(void) {
    int N = 0;
    int arr[501][501] = {0, };
    int res[501][501] = {0, };
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    res[0][0] = arr[0][0];
    for(int i = 1; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            if(j == 0) {
                res[i][j] = arr[i][j] + res[i-1][j];
            } else if(j == i) {
                res[i][j] = arr[i][j] + res[i-1][j-1];
            } else {
                res[i][j] = arr[i][j] + max(res[i-1][j], res[i-1][j-1]);
            }
        }
    }
    
    int max_res = -1;
    
    for(int i = 0; i < N; i++) {
        max_res = max(max_res, res[N-1][i]);
    }
    
    printf("%d\n", max_res);
    
}
