/*
 *
 *  2020.02.02
 *  https://www.acmicpc.net/problem/10773
 *
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int top;
    long long int data[100001];
} stack;

void PUSH(stack* s, long long int element) {
    s->data[s->top] = element;
    s->top++;
}

long long int POP(stack* s) {
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
    stack* s = (stack*)malloc(sizeof(stack));
    int N;
    long long int tmp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%lld", &tmp);
        if(tmp == 0) {
            POP(s);
        } else {
            PUSH(s, tmp);
        }
    }
    
    long long int res = 0;
    
    while(isEmpty(s) == 0) {
        res += POP(s);
    }
    printf("%lld\n", res);
}

