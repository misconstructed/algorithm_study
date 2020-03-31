/*
 *
 *  2020.03.30
 *  https://www.acmicpc.net/problem/14499
 *
 */

#include <stdio.h>
#include <stdlib.h>

int n;
int m;
int x;
int y;
int k;

int** arr;
int* move;

// oppisite index
int opp[6][2] = {{1, 6}, {2, 5}, {3, 4}, {4, 3}, {5, 2}, {6, 1}};

// direction
// 1(동), 2(서), 3(북), 4(남)
int dx[] = {+1, -1, 0, 0};
int dy[] = {0, 0, -1, +1};

// 주사위에 적힌 숫자(1~6)
int res[] = {0, 0, 0, 0, 0, 0};

int up_down[] = {2, 5};
int right_left[] = {3, 4};
int center[] = {1, 6};

int up;
int bottom;
int top;
int value;
 
int main(void) {
    int i = 0;
    int j = 0;
    
    up = 2;
    bottom = 1;
    top = 6;
    
    scanf("%d %d %d %d %d", &n, &m, &y, &x, &k);
    
    move = (int*)malloc(sizeof(int) * k);
    arr = (int**)malloc(sizeof(int*) * n);
    
    for(i = 0; i < n; ++i) {
        arr[i] = (int*) malloc(sizeof(int) * m);
        for(j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for(i = 0; i < k; ++i) {
        scanf("%d", &move[i]);
   
        
        int tmpa = 0;
        int tmpb = 0;
        
        // new x, new y
        int tmpx = x + dx[move[i] - 1];
        int tmpy = y + dy[move[i] - 1];
        
        // out of bound : print nothing, continue
        if(tmpx < 0 || tmpx >= m || tmpy < 0 || tmpy >= n) {
            continue;
        }
        
        x = tmpx;
        y = tmpy;
        
        value = arr[tmpy][tmpx];
        
        tmpa = center[0];
        tmpb = center[1];
        
        if(move[i] == 1) {
            // 동
            center[0] = right_left[0];
            center[1] = right_left[1];
            right_left[0] = tmpb;
            right_left[1] = tmpa;
        } else if(move[i] == 2) {
            // 서
            center[0] = right_left[1];
            center[1] = right_left[0];
            right_left[0] = tmpa;
            right_left[1] = tmpb;
        } else if(move[i] == 3) {
            // 남
            center[0] = up_down[0];
            center[1] = up_down[1];
            up_down[0] = tmpb;
            up_down[1] = tmpa;
        } else if(move[i] == 4) {
            // 북
            center[0] = up_down[1];
            center[1] = up_down[0];
            up_down[0] = tmpa;
            up_down[1] = tmpb;
        }
        
        if(value == 0) {
            // 주사위의 값을 복사
            arr[y][x] = res[center[0] - 1];
        } else {
            // 주사위에 값을 복사
            res[center[0] - 1] = arr[y][x];
            arr[y][x] = 0;
        }
        
        printf("%d\n", res[center[1] -1]);
    }
}

