/*
 *
 *  2020.03.05
 *  https://www.acmicpc.net/problem/10807
 *
 */

#include <stdio.h>

int arr[205];
int N;
int index;
int bound = 100;

int main(void) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &index);
        arr[index + bound]++;
    }
    scanf("%d", &index);
    printf("%d\n", arr[index+bound]);
}

