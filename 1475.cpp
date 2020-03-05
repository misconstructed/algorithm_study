/*
 *
 *  2020.03.05
 *  https://www.acmicpc.net/problem/1475
 *
 */

#include <stdio.h>

long long int n;
int arr[15];

int main(void) {
    scanf("%lld", &n);
    int max = -1;
    if(n == 0) {
        printf("1\n");
        return 0;
    }
    while(n != 0) {
        int tmp = n % 10;
        n = n / 10;
        arr[tmp]++;
        if(tmp != 6 && tmp != 9)
            if(max < arr[tmp])
                max = arr[tmp];
    }
    int m = arr[6] + arr[9];
    if(m % 2 == 0)
        m = m / 2;
    else
        m = m / 2 + 1;
    
    if(m < max)
        printf("%d\n", max);
    else
        printf("%d\n", m);
}

