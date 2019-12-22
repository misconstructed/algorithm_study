/*
 *
 *  2019.12.22
 *  https://www.acmicpc.net/problem/1904
 *
*/

#include <stdio.h>

int main(void) {
    long long int arr[1000001] = {0, };
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    int mod = 15746;
    int N;
    scanf("%d", &N);
    for(int i = 3; i <= N; i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % mod;
    }
    printf("%lld\n", arr[N]);
}

