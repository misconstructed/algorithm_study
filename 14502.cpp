/*
 *
 *  2020.04.02
 *  https://www.acmicpc.net/problem/14502
 *  reference : https://jaimemin.tistory.com/601
 *
 */

#include <stdio.h>
#include <stdlib.h>

int n;
int m;
int** arr;
int virus_count = 0;
int wall_count;
int all;
int max = 0;

/* virus queue : BFS */
typedef struct _point {
    int x;
    int y;
} point;

point* queue;
int front = 0;
int rear = 0;

void init() {
    front = 0;
    rear = 0;
}

void enqueue(point p) {
    queue[rear++] = p;
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

int size() {
    return rear - front;
}
/* end queue */


int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, +1, -1};

void BFS() {
    int i = 0;
    int j = 0;
    int tmp_virus_count = virus_count;
    point tmp;
    
    // init queue
    init();
    
    // copy original
    int** bfs = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        bfs[i] = (int*)malloc(sizeof(int) * m);
        for(j = 0; j < m; j++) {
            bfs[i][j] = arr[i][j];
            if(bfs[i][j] == 2) {
                tmp = {j, i};
                enqueue(tmp);
            }
        }
    }
    
    while(!empty()) {
        tmp = dequeue();
        
        for(i = 0; i < 4; i++) {
            int new_x = tmp.x + dx[i];
            int new_y = tmp.y + dy[i];
            
            // out of range
            if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
                continue;
            
            // new virus area
            if(bfs[new_y][new_x] == 0) {
                bfs[new_y][new_x] = 2;
                tmp_virus_count++;
                point n = {new_x, new_y};
                enqueue(n);
            }
        }
    }
    
    int res = all - wall_count - tmp_virus_count;
    
    if(res > max)
        max = res;
    
}

void make_walls(int count, int _i, int _j) {
    int i = _i;
    int j = _j + 1;
    
    if(count == 3) {
        BFS();
        return;
    }
    
    for(j = _j + 1; j < m; j++) {
        if(arr[i][j] == 0) {
            arr[i][j] = 1;
            make_walls(count + 1, i, j);
            arr[i][j] = 0;
        }
    }
    for(i = _i + 1; i < n; i++) {
        for(j = 0; j < m; j++) {
            if(arr[i][j] == 0) {
                arr[i][j] = 1;
                make_walls(count + 1, i, j);
                arr[i][j] = 0;
            }
        }
    }
}

int main(void) {
    int i = 0;
    int j = 0;
    scanf("%d %d", &n, &m);
    
    all = n * m;
    queue = (point*)malloc(sizeof(queue) * (m * n + 2));
    
    arr = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
        for(j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 2) {
                virus_count++;
            } else if(arr[i][j] == 1) {
                wall_count++;
            }
        }
    }
    
    // will be making 3 more walls
    wall_count += 3;
    make_walls(0, 0, -1);
    
    printf("%d\n", max);
}

