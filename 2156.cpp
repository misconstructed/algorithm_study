/*
 *
 *  2020.01.02
 *  https://www.acmicpc.net/problem/2156
 *
*/

#include <stdio.h>

long long int max(long long int a, long long int b) {
    if(a > b) return a;
    else return b;
}

int main(void) {
    int n = 0;
    int arr[10001] = {0, };
    long long int zero[10001] = {0, };
    long long int one[10001] = {0, };
    long long int two[10001] = {0, };
    
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &arr[i]);
    }
    zero[0] = 0;
    one[0] = 0;
    two[0] = 0;
    
    zero[1] = 0;
    one[1] = arr[1];
    two[1] = arr[1];
    
    
    for(int i = 2; i <= n; i++) {
        // 현재 포도주를 마시지 않는 경우도 고려해야 함.
        zero[i] = max(zero[i-1], max(one[i-1], two[i-1]));
        one[i] = max(zero[i-1], two[i-1]) + arr[i];
        two[i] = max(one[i-2], zero[i-1]) + arr[i];
    }
    
    long long int res = -1;
    for(int i = 1; i <= n; i++) {
        res = max(res, max(zero[i], max(one[i], two[i])));
    }
    printf("%lld\n", res);
}

