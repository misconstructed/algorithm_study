/*
 *
 *  2020.04.07
 *  https://www.acmicpc.net/problem/14890
 *
*/

#include <stdio.h>
#include <stdlib.h>

int n;
int l;

int** input;

int res = 0;

typedef struct _point {
    int index;
    // 0 : no slope, 1 : up, 2 : down
    int slope;
} point;

/* queue */

point* queue;
int front;
int rear;

void init() {
    front = 0;
    rear = 0;
}

void enqueue(point index) {
    queue[rear++] = index;
}

point dequeue() {
    return queue[front++];
}

int empty() {
    if(front == rear)
        return 1;
    else
        return 0;
}

/* end queue */

int main(void) {
    int i = 0;
    int j = 0;
    
    scanf("%d %d", &n, &l);
    
    queue = (point*)malloc(sizeof(point) * n * n);
    
    input = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        input[i] = (int*)malloc(sizeof(int) * n);
        for(j = 0; j < n; j++) {
            scanf("%d", &input[i][j]);
        }
    }
    
    point current_point;
    int current_index = 0;
    int current_slope = 0;
    int current_value = 0;
    int next_index = 0;
    int next_value = 0;
    int slope_index = 0;
    int slope_value = 0;
    int flag = 0;
    
    point tmp;
    
    // 가로
    for(i = 0; i < n; i++) {
        init();
        point first = {0, 0};
        enqueue(first);
        while(!empty()) {
            current_point = dequeue();
            current_index = current_point.index;
            current_slope = current_point.slope;
            
            if(current_index == (n-1)) {
                res++;
                break;
            }
            current_value = input[i][current_index];
            
            // same level
            next_index = current_index + 1;
            if(next_index < n) {
                next_value = input[i][next_index];
                if(next_value == current_value) {
                    tmp = {next_index, 0};
                    enqueue(tmp);
                }
            }
            
            
            // going down, last index
            slope_index = current_index + l;
            
            if(slope_index < n) {
                slope_value = input[i][slope_index];
                if(slope_value == current_value - 1) {
                    flag = 0;
                    if(l > 1) {
                        for(j = 1; j < l; j++) {
                            if(input[i][current_index + j] != input[i][current_index + j + 1])
                                flag = 1;
                        }
                    }
                    if(flag == 0) {
                        tmp = {slope_index, 2};
                        enqueue(tmp);
                    }
                }
            }
            
            // 겹치지 않도록
            if(current_slope != 2) {
                // up slope
                slope_index = current_index + l;
                if(slope_index < n) {
                    slope_value = input[i][slope_index];
                    if(slope_value == current_value + 1) {
                        flag = 0;
                        
                        for(j = 0; j < l-1; j++) {
                            if(input[i][current_index + j] != input[i][current_index + j + 1]) {
                                flag = 1;
                            }
                        }
                        
                        if(flag == 0) {
                            tmp = {slope_index, 1};
                            enqueue(tmp);
                        }
                    }
                }
            }
        }
    }
    
    // 세로
    for(i = 0; i < n; i++) {
        init();
        point first = {0, 0};
        enqueue(first);
        while(!empty()) {
            current_point = dequeue();
            current_index = current_point.index;
            current_slope = current_point.slope;
            
            if(current_index == (n-1)) {
                res++;
                break;
            }
            current_value = input[current_index][i];
            
            
            // same level
            next_index = current_index + 1;
            if(next_index < n) {
                next_value = input[next_index][i];
                if(next_value == current_value) {
                    tmp = {next_index, 0};
                    enqueue(tmp);
                }
            }
            
            // going down, last index
            slope_index = current_index + l;
            if(slope_index < n) {
                slope_value = input[slope_index][i];
                if(slope_value == current_value - 1) {
                    flag = 0;
                    if(l > 1) {
                        for(j = 1; j < l; j++) {
                            if(input[current_index + j][i] != input[current_index + j + 1][i])
                                flag = 1;
                        }
                    }
                    if(flag == 0) {
                        tmp = {slope_index, 2};
                        enqueue(tmp);
                    }
                }
            }
            
            // 겹치지 않도록
            if(current_slope != 2) {
                // up slope
                slope_index = current_index + l;
                if(slope_index < n) {
                    slope_value = input[slope_index][i];
                    if(slope_value == current_value + 1) {
                        flag = 0;
                        
                        for(j = 0; j < l-1; j++) {
                            if(input[current_index + j][i] != input[current_index + j + 1][i])
                                flag = 1;
                        }
                        
                        if(flag == 0) {
                            tmp = {slope_index, 1};
                            enqueue(tmp);
                        }
                    }
                }
            }
        }
    }
    
    printf("%d\n", res);
}

