/*
 *
 *  2020.03.24
 *  https://www.acmicpc.net/problem/13460
 *  출처 : https://www.youtube.com/watch?v=SarTy3ZwmVo
 *
 */

#include <stdio.h>
#include <stdlib.h>

int n;
int m;
char** arr;

char block = '#';
char red = 'R';
char blue = 'B';
char road = '.';
char hole = 'O';

// 두 값 차이의 절대값 구하기
int abs(int a, int b) {
    if(a > b)
        return a-b;
    else
        return b-a;
}

// 좌표를 저장하는 구조체 생성
typedef struct _cord {
    int rx;
    int ry;
    int bx;
    int by;
    int count;
} cord;

/* queue def */
cord queue[101];
int front;
int rear;

int empty(){
    if(rear - front == 0)
        return 1;
    else
        return 0;
}

void enqueue(cord c) {
    queue[rear++] = c;
}

cord dequeue() {
    return queue[front++];
}
/* end queue def */

// 상하좌우 움직이는 방향
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

// 방문한적이 있는지 확인
int visited[10][10][10][10];

int main(void) {
    int i, j;
    cord org;
    scanf("%d %d", &n, &m);
    
    // 배열 초기화
    arr = (char**)malloc(sizeof(char*) * (n+1));
    for(i = 0; i < n; i++) {
        arr[i] = (char*)malloc(sizeof(char) * (m+1));
    }
    
    // 입력 받음
    for(i = 0; i < n; i++) {
        scanf("%s", arr[i]);
        for(j = 0; j < m; j++) {
            if(arr[i][j] == red) {
                org.rx = j;
                org.ry = i;
            } else if(arr[i][j] == blue) {
                org.bx = j;
                org.by = i;
            }
        }
    }
    
    // 큐에 삽입
    org.count = 0;
    enqueue(org);
    // 방문 표시
    visited[org.ry][org.rx][org.by][org.bx] = 1;
    int res = -1;
    
    while(!empty()) {
        cord c = dequeue();
        // 10 번을 넘긴 경우 -1
        if(c.count > 10)
            break;
        // 빨간 공은 들어갔고, 파란 공은 들어가지 않은 경우 성공
        if(arr[c.ry][c.rx] == hole && arr[c.by][c.bx] != hole) {
            res = c.count;
            break;
        }
        
        // 상하좌우에 대해서
        for(i = 0; i < 4; ++i) {
            // 다음 좌표
            int next_rx= c.rx;
            int next_ry = c.ry;
            int next_bx = c.bx;
            int next_by = c.by;
            
            while(1) {
                // 현재 위치가 벽이 아니고 구멍도 아닌 경우 이동
                if(arr[next_ry][next_rx] != block && arr[next_ry][next_rx] != hole) {
                    next_ry += dy[i];
                    next_rx += dx[i];
                } else {
                    // 현재 위치가 벽인 경우, 한 칸 되돌아가고 이동 중지(break)
                    if(arr[next_ry][next_rx] == block) {
                        next_ry -= dy[i];
                        next_rx -= dx[i];
                    }
                    break;
                }
            }
            
            while(1) {
                // 현재 위치가 벽이 아니고 구멍도 아닌 경우 이동
                if(arr[next_by][next_bx] != block && arr[next_by][next_bx] != hole) {
                    next_by += dy[i];
                    next_bx += dx[i];
                } else {
                    // 현재 위치가 벽인 경우, 한 칸 되돌아가고 이동 중지(break)
                    if(arr[next_by][next_bx] == block) {
                        next_by -= dy[i];
                        next_bx -= dx[i];
                    }
                    break;
                }
            }
            
            // 빨간 공과 파란 공의 위치가 같은 경우, 더 많이 움직인 공은 한 칸 뒤로 이동
            if(next_rx == next_bx && next_ry == next_by) {
                if(arr[next_ry][next_rx] != hole) {
                    int r_moved = abs(c.rx, next_rx) + abs(c.ry, next_ry);
                    int b_moved = abs(c.bx, next_bx) + abs(c.by, next_by);
                    if(r_moved > b_moved) {
                        next_rx -= dx[i];
                        next_ry -= dy[i];
                    } else {
                        next_bx -= dx[i];
                        next_by -= dy[i];
                    }
                }
            }
            
            // 현재 위치가 방문한 적이 없는 경우, 큐에 삽입
            if(visited[next_ry][next_rx][next_by][next_bx] == 0) {
                visited[next_ry][next_rx][next_by][next_bx] = 1;
                cord n;
                n.rx = next_rx;
                n.ry = next_ry;
                n.bx = next_bx;
                n.by = next_by;
                n.count = c.count + 1;
                enqueue(n);
            }
        }
    }
    printf("%d\n", res);
}

