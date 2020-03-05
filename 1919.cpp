/*
 *
 *  2020.03.05
 *  https://www.acmicpc.net/problem/1919
 *
 */

#include <stdio.h>

char a[1001];
char b[1001];

int a_a[30];
int a_b[30];

int count1;
int count2;

char A = 'a';

int max;

int abs(int x, int y) {
    int res = x - y;
    if(res < 0) return -1 * res;
    else return res;
}

int main(void) {
    scanf("%s", a);
    scanf("%s", b);
    int i = 0;
    while(a[i] != '\0') {
        a_a[a[i] - A]++;
        i++;
        count1++;
    }
    i = 0;
    while(b[i] != '\0') {
        a_b[b[i] - A]++;
        i++;
        count2++;
    }
    int res = 0;
    for(i = 0; i < 30; i++) {
        res += abs(a_a[i], a_b[i]);
    }
    printf("%d\n", res);
}

