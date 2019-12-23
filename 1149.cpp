/*
 *
 *  2019.12.23
 *  https://www.acmicpc.net/problem/1149
 *
*/

/*
 * 최소 비용을 구해라 == DP 문제
 */

#include <stdio.h>

int min(int a, int b) {
    if(a < b) return a;
    else return b;
}

int trimin(int a, int b, int c) {
    int tmp = min(a, b);
    return min(tmp, c);
}

int main(void) {
    int N = 0;
    int r, g, b;
    int arr[1001][3] = {0, };
    int res[1001][3] = {0, };
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d %d", &r, &g, &b);
        arr[i][0] = r;
        arr[i][1] = g;
        arr[i][2] = b;
    }
    if(N == 0) {
        printf("0\n");
        return 0;
    }
    res[0][0] = arr[0][0];
    res[0][1] = arr[0][1];
    res[0][2] = arr[0][2];
    
    for(int i = 1; i < N; i++) {
        res[i][0] = min(arr[i][0] + res[i-1][1], arr[i][0] + res[i-1][2]);
        res[i][1] = min(arr[i][1] + res[i-1][0], arr[i][1] + res[i-1][2]);
        res[i][2] = min(arr[i][2] + res[i-1][0], arr[i][2] + res[i-1][1]);
    }
    
    int result = trimin(res[N-1][0], res[N-1][1], res[N-1][2]);
    printf("%d\n", result);
}

