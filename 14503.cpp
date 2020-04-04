/*
 *
 *  2020.04.03
 *  https://www.acmicpc.net/problem/14503
 *
 */

#include <stdio.h>
#include <stdlib.h>

int n;
int m;

int x;
int y;
int dir;
int** arr;

int res = 0;

/* stack */

typedef struct _point{
    int x;
    int y;
} point;

int pointer;
point* stack;

void init() {
    pointer = 0;
}

void push(point p) {
    stack[pointer++] = p;
}

point pop() {
    return stack[--pointer];
}

point top() {
    return stack[pointer-1];
}

int empty() {
    if(pointer == 0)
        return 1;
    else
        return 0;
}

int size() {
    return pointer;
}

/* end stack */

// up(0), right(1), down(2), left(3)
// move dir : 0 -> 3 -> 2 -> 1 -> 0 (-1)
// move back : 0 -> 2, 2 -> 0, 1 -> 3, 3 -> 1 (+2)
int d = 4;
int dx[] = {0, 1, 0, -1};
int dy[] = {-1, 0, +1, 0};

int main(void) {
    int i = 0;
    int j = 0;
    
    point p;
    /* get input */
    scanf("%d %d", &n, &m);

    // make stack
    stack = (point*)malloc(sizeof(point) * (n * m + 1));
    init();

    scanf("%d %d %d", &y, &x, &dir);
    
    // make map
    arr = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        arr[i] = (int*)malloc(sizeof(int) * m);
        for(j = 0; j < m; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    /* end input */
    
    // init starting point
    p.x = x;
    p.y = y;
    // cleaned
    arr[p.y][p.x] = 2;
    // increase clean area
    res++;
    push(p);
    
    int new_x = 0;
    int new_y = 0;
  
    while(!empty()) {
        p = pop();
        // if the area is a wall, end searching
        if(arr[p.y][p.x] == 1) {
            break;
        }
        int found = 0;
        for(i = 1; i <= 4; i++) {
            // new direction
            int new_dir = dir - i;
            if(new_dir < 0)
                new_dir += 4;
            
            new_x = p.x + dx[new_dir];
            new_y = p.y + dy[new_dir];
            // check point range
            if(new_x < 0 || new_x >= m || new_y < 0 || new_y >= n)
                continue;
            else {
                // not cleaned area
                if(arr[new_y][new_x] == 0) {
                    dir = new_dir;
                    found = 1;
                    break;
                } else {
                    // already cleaned || wall
                    continue;
                }
            }
        }
        
        if(found == 1) {
            arr[new_y][new_x] = 2;
            res++;
            point tmp = {new_x, new_y};
            push(tmp);
        } else {
            // go opposite direction
            int tmp_x = p.x;
            int tmp_y = p.y;
            while(arr[tmp_y][tmp_x] == 2) {
                int tmp_dir = dir - 2;
                if(tmp_dir < 0)
                    tmp_dir += d;
                tmp_x += dx[tmp_dir];
                tmp_y += dy[tmp_dir];
                if(arr[tmp_y][tmp_x] == 2) {
                    point tmp = {tmp_x, tmp_y};
                    push(tmp);
                    break;
                }
            }
        }
    }
    printf("%d\n", res);
}

