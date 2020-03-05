/*
 *
 *  2020.03.05
 *  https://www.acmicpc.net/problem/13300
 *
 */

#include <stdio.h>

int n;
int k;

int s;
int g;

int male[10];
int female[10];


int main(void) {
    scanf("%d %d", &n, &k);
    for(int i = 0; i  < n; i++) {
        scanf("%d %d", &s, &g);
        if(s == 0) {
            male[g]++;
        } else {
            female[g]++;
        }
    }
    int res = 0;
    for(int i = 0; i < 10; i++) {
        if(male[i] % k == 0) res += (male[i] / k);
        else res += (male[i] / k + 1);
        
        if(female[i] % k == 0) res += (female[i] / k);
        else res += (female[i] / k + 1);
    }
    printf("%d\n", res);
}

