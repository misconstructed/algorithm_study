/*
 *
 *  2020.03.05
 *  https://www.acmicpc.net/problem/2577
 *
 */

#include <stdio.h>

int arr[15];
int a;
int b;
int c;
long long int res;

int main(void) {
    scanf("%d\n%d\n%d", &a, &b, &c);
    res = a * b * c;
    while(res != 0) {
        int tmp = res % 10;
        res = res / 10;
        arr[tmp]++;
    }
    for(int i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }
}

