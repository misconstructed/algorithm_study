/*
 *
 *  2019.12.29
 *  https://www.acmicpc.net/problem/2579
 *
*/

#include <stdio.h>

long long int max(long long int a, long long int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    int n = 0;
    long long int points[301] = {0, };
    long long int one[301] = {0, };
    long long int two[301] = {0, };
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &points[i]);
    }
    
    one[0] = 0;
    two[0] = 0;
    one[1] = points[1];
    two[1] = 0;
    
    one[2] = max(one[1], two[1]) + points[2];
    two[2] = max(one[0], two[0]) + points[2];
    
    for(int i = 3; i <= n; i++) {
        one[i] = two[i-1] + points[i];
        two[i] = max(one[i-2], two[i-2]) + points[i];
    }
    
    printf("%lld", max(one[n], two[n]));
}

