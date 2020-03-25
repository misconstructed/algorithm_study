/*
 *
 *  2020.03.25
 *  https://www.acmicpc.net/problem/3190
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct _cord{
    int x;
    int y;
} cord;

typedef struct _node {
    int visited;
    int apple;
} node;

typedef struct _action {
    int time;
    char dir;
    int size;
} action;

int N;
int K;
int L;
node **arr;

int x;
int y;

int X;
char C;

/* queue */
action* head_queue;
int head_front;
int head_rear;

action* tail_queue;
int tail_front;
int tail_rear;

void enqueue(action a, int flag){
    if(flag == 0) {
        head_queue[head_rear++] = a;
    } else {
        tail_queue[tail_rear++] = a;
    }
}

action top(int flag) {
    if(flag == 0) {
        return head_queue[head_front];
    } else {
        return tail_queue[tail_front];
    }
}

void dequeue(int flag) {
    if(flag == 0)
        head_front++;
    else
        tail_front++;
}

int empty(int flag) {
    if(flag == 0) {
        if(head_rear - head_front == 0)
            return 1;
        else
            return 0;
    } else {
        if(tail_rear - tail_front == 0)
            return 1;
        else
            return 0;
    }
}
/* end queue */

int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, +1, -1};
// index : {L, D}
int next[4][2] = {{2, 3}, {3, 2}, {1, 0}, {0, 1}};

char l = 'L';
char d = 'D';


int main(void) {
    int i, j;
    scanf("%d\n%d", &N, &K);
    arr = (node**)malloc(sizeof(node*) * N);
    for(i = 0; i < N; ++i) {
        arr[i] = (node*)malloc(sizeof(node) * N);
        for(j = 0; j < N; j++) {
            arr[i][j].visited = 0;
            arr[i][j].apple = 0;
        }
    }
    
    for(i = 0; i < K; ++i) {
        scanf("%d %d", &y, &x);
        arr[y-1][x-1].apple = 1;
    }
    
    scanf("%d", &L);
    
    head_queue = (action*)malloc(sizeof(action) * (L+1));
    tail_queue = (action*)malloc(sizeof(action) * (L+1));
    
    for(i = 0; i < L; ++i) {
        scanf("%d %c", &X, &C);
        action a;
        a.time = X;
        a.dir = C;
        a.size = 1;
        enqueue(a, 0);
    }
    
    int count = 0;
    int size = 1;
    int head_dir = 1;
    int tail_dir = 1;
    cord head = {0, 0};
    cord tail = {0, 0};
    arr[0][0].visited = 1;
    
    while(1) {
        
        if(!empty(0)) {
            action a = top(0);
            if(a.time == count) {
                dequeue(0);
                // move left
                if(a.dir == l) {
                    head_dir = next[head_dir][0];
                }
                // move right
                else if(a.dir == d) {
                    head_dir = next[head_dir][1];
                }
                
                a.time += (size-1);
                a.size = size;
                
                // insert action in tail queue
                enqueue(a, 1);
            }
        }
        
        // move head
        head.x += dx[head_dir];
        head.y += dy[head_dir];
        
        // end option
        // hit wall
        if(head.x < 0 || head.x >= N || head.y < 0 || head.y >= N)
            break;
    
        // hit self
        if(arr[head.y][head.x].visited == 1)
            break;
        
        arr[head.y][head.x].visited = 1;
        
        // no apple (move tail)
        if(arr[head.y][head.x].apple == 0) {
            arr[tail.y][tail.x].visited = 0;
            
            if(!empty(1)) {
                // change dir
                action a = top(1);
                if(a.time + (size - a.size) == count) {
                    dequeue(1);
                    // move left
                    if(a.dir == l) {
                        tail_dir = next[tail_dir][0];
                    }
                    // move right
                    else if(a.dir == d) {
                        tail_dir = next[tail_dir][1];
                    }
                }
            }
            
            // move tail
            tail.x += dx[tail_dir];
            tail.y += dy[tail_dir];
        } else {
            // apple : increase size
            size++;
            // apple already used
            arr[head.y][head.x].apple = 0;
        }
        
        count++;
    }
    printf("%d\n", count+1);
    return 0;
}

