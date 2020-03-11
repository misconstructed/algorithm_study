/*
 *
 *  2020.03.11
 *  https://www.acmicpc.net/problem/10828
 *
 */

#include <stdio.h>
#include <string.h>

int arr[10001];
int n;
int pos = 0;
int num;
char op[10];

int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", op);
        if(strcmp(op, "push") == 0) {
            scanf("%d", &num);
            arr[pos++] = num;
        } else if(strcmp(op, "top") == 0) {
            if(pos != 0)
                printf("%d\n", arr[pos-1]);
            else
                printf("-1\n");
        } else if(strcmp(op, "size") == 0) {
            printf("%d\n", pos);
        } else if(strcmp(op, "pop") == 0) {
            if(pos != 0)
                printf("%d\n", arr[--pos]);
            else
                printf("-1\n");
        } else if(strcmp(op, "empty") == 0) {
            if(pos == 0)
                printf("1\n");
            else
                printf("0\n");
        }
    }
}

