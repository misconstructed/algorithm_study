/*
 *
 *  2020.02.02
 *  https://www.acmicpc.net/problem/9012
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int top;
    char data[51];
} stack;

void PUSH(stack* s, char element) {
    s->data[s->top] = element;
    s->top++;
}

char POP(stack* s) {
    s->top--;
    return s->data[s->top];
}

int isEmpty(stack* s) {
    if(s->top == 0) {
        return 1;
    } else {
        return 0;
    }
}


int main(void) {
    int flag = 0;
    int N;
    char input[100][51];
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%s", input[i]);
    }
    for(int i = 0; i < N; i++) {
        stack* s = (stack*)malloc(sizeof(stack));
        s->top = 0;
        flag = 0;
        for(int j = 0; j < strlen(input[i]); j++) {
            if(input[i][j] == '(') {
                PUSH(s, '(');
            } else if(input[i][j] == ')') {
                if(isEmpty(s) == 1) {
                    flag = 1;
                    break;
                }
                POP(s);
            }
        }
        if(flag == 1) {
            printf("NO\n");
        } else if(isEmpty(s) == 0) {
            printf("NO\n");
        } else {
            printf("YES\n");
        }
    }
}

