/*
 *
 *  2020.03.19
 *  https://www.acmicpc.net/problem/2164
 *
 */

#include <stdio.h>

int arr[5000005];
int front = 0;
int back = 0;

void queue_push(int x) {
    arr[back++] = x;
}

int queue_pop() {
    if(front == back)
        return -1;
    else
        return arr[front++];
}

int queue_empty() {
    if(front == back)
        return 1;
    else
        return 0;
}

int queue_size() {
    return back - front;
}


int main(void) {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        queue_push(i);
    }
    while(queue_empty() == 0) {
        if(queue_size() == 1) {
            printf("%d\n", queue_pop());
            break;
        }
        queue_pop();
        int val = queue_pop();
        queue_push(val);
    }
}

