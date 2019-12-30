/*
 *
 *  2019.12.30
 *  https://www.acmicpc.net/problem/10844
 *
*/

#include <stdio.h>

int main(void) {
    long long int arr[101][10] = {{0, 1, 1, 1, 1, 1, 1, 1, 1, 1},};
    long long int mod = 1000000000;
    int n = 0;
    scanf("%d", &n);
    for(int i = 1; i < n; i++) {
        for(int j = 0; j <= 9; j++) {
            if(j == 0) {
                arr[i][j] = arr[i-1][j+1] % mod;
            } else if(j == 9) {
                arr[i][j] = arr[i-1][j-1] % mod;
            } else {
                arr[i][j] = (arr[i-1][j-1] + arr[i-1][j+1]) % mod;
            }
        }
    }
    long long int sum = 0;
    for(int i = 0; i <= 9; i++) {
        sum += arr[n-1][i];
    }
    printf("%lld\n", sum % mod);
    
}

