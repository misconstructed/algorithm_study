/*
 *
 *  2020.02.01
 *  https://www.acmicpc.net/problem/10828
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    long long int arr[10001];
    int top;
} stack;

void push_stack(stack* s, long long int data) {
    int index = s->top;
    s->arr[index] = data;
    s->top++;
}

long long int pop_stack(stack* s, long long int data) {
    int index = s->top;
    if(index == 0) {
        return -1;
    }
    s->top--;
    return s->arr[s->top];
}

int size_stack(stack* s) {
    return s->top;
}

int empty_stack(stack* s) {
    if(s->top == 0)
        return 1;
    else
        return 0;
}

long long int top_stack(stack* s) {
    if(s->top == 0) {
        return -1;
    } else {
        return s->arr[s->top - 1];
    }
}

int main(void) {
    int N = 0;
    stack* s = (stack*)malloc(sizeof(s));
    s->top = 0;
    char op[10001][10];
    long long int oper[10001];
    
    char push[10] = "push";
    char pop[10] = "pop";
    char size[10] = "size";
    char empty[10] = "empty";
    char top[10] = "top";
    char input[10];
    long long int tmp;
    scanf("%d", &N);
    
    for(int i = 0; i < N; i++) {
        scanf("%s", input);
        if(strcmp(input, push) == 0) {
            scanf("%lld", &tmp);
            strcpy(op[i], input);
            oper[i] = tmp;
        } else if(strcmp(input, pop) == 0) {
            strcpy(op[i], input);
            oper[i] = tmp;
        } else if(strcmp(input, size) == 0) {
            strcpy(op[i], input);
        } else if(strcmp(input, empty) == 0) {
            strcpy(op[i], input);
        } else if(strcmp(input, top) == 0) {
            strcpy(op[i], input);
        }
    }
    
    for(int i = 0; i < N; i++) {
        if(strcmp(op[i], push) == 0) {
            push_stack(s, oper[i]);
        } else if(strcmp(op[i], pop) == 0) {
            printf("%lld\n", pop_stack(s, oper[i]));
        } else if(strcmp(op[i], size) == 0) {
            printf("%d\n", size_stack(s));
        } else if(strcmp(op[i], empty) == 0) {
            printf("%d\n", empty_stack(s));
        } else if(strcmp(op[i], top) == 0) {
            printf("%lld\n", top_stack(s));
        }
    }
}



