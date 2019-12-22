/*
 *
 *  2019.12.21
 *  https://www.acmicpc.net/problem/2748
 *
*/

#include <stdio.h>
int main(void) {
    long long int arr[91] = {0, };
    int N;
    arr[0] = 0;
    arr[1] = 1;
    
    scanf("%d", &N);
    for(int i = 2; i <= N; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    printf("%lld\n", arr[N]);
}

