/*
 *
 *  2020.03.19
 *  https://www.acmicpc.net/problem/18258
 *
 */

#include <stdio.h>

int arr[2000005];
int front = 0;
int back = 0;
int n;
int val;
char op[10];

int strcmp(char* a, char* b) {
    int i = 0;
    while(a[i] != '\0') {
        if(a[i] != b[i])
            return 0;
        i++;
    }
    return 1;
}

void stack_push(int x) {
    arr[back++] = x;
}

int stack_pop() {
    if(front != back)
        return arr[front++];
    else
        return -1;
}

int stack_size() {
    return back - front;
}

int stack_empty() {
    if(back == front)
        return 1;
    else
        return 0;
}

int stack_front() {
    if(stack_empty() == 1)
        return -1;
    else
        return arr[front];
}

int stack_back() {
    if(stack_empty() == 1)
        return -1;
    else
        return arr[back-1];
}

int main(void) {
    char pu[10] = "push";
    char po[10] = "pop";
    char si[10] = "size";
    char em[10] = "empty";
    char fr[10] = "front";
    char ba[10] = "back";
    
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", op);
        if(strcmp(op, pu) == 1) {
            scanf("%d", &val);
            stack_push(val);
        } else if(strcmp(op, po) == 1) {
            val = stack_pop();
            printf("%d\n", val);
        } else if(strcmp(op, si) == 1) {
            val = stack_size();
            printf("%d\n", val);
        } else if(strcmp(op, em) == 1) {
            val = stack_empty();
            printf("%d\n", val);
        } else if(strcmp(op, fr) == 1) {
            val = stack_front();
            printf("%d\n", val);
        } else if(strcmp(op, ba) == 1) {
            val = stack_back();
            printf("%d\n", val);
        }
    }
}

