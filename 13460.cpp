/*
 *
 *  2020.03.24
 *  https://www.acmicpc.net/problem/13460
 *  ��ó : https://www.youtube.com/watch?v=SarTy3ZwmVo
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

// �� �� ������ ���밪 ���ϱ�
int abs(int a, int b) {
    if(a > b)
        return a-b;
    else
        return b-a;
}

// ��ǥ�� �����ϴ� ����ü ����
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

// �����¿� �����̴� ����
int dx[] = {-1, +1, 0, 0};
int dy[] = {0, 0, -1, +1};

// �湮������ �ִ��� Ȯ��
int visited[10][10][10][10];

int main(void) {
    int i, j;
    cord org;
    scanf("%d %d", &n, &m);
    
    // �迭 �ʱ�ȭ
    arr = (char**)malloc(sizeof(char*) * (n+1));
    for(i = 0; i < n; i++) {
        arr[i] = (char*)malloc(sizeof(char) * (m+1));
    }
    
    // �Է� ����
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
    
    // ť�� ����
    org.count = 0;
    enqueue(org);
    // �湮 ǥ��
    visited[org.ry][org.rx][org.by][org.bx] = 1;
    int res = -1;
    
    while(!empty()) {
        cord c = dequeue();
        // 10 ���� �ѱ� ��� -1
        if(c.count > 10)
            break;
        // ���� ���� ����, �Ķ� ���� ���� ���� ��� ����
        if(arr[c.ry][c.rx] == hole && arr[c.by][c.bx] != hole) {
            res = c.count;
            break;
        }
        
        // �����¿쿡 ���ؼ�
        for(i = 0; i < 4; ++i) {
            // ���� ��ǥ
            int next_rx= c.rx;
            int next_ry = c.ry;
            int next_bx = c.bx;
            int next_by = c.by;
            
            while(1) {
                // ���� ��ġ�� ���� �ƴϰ� ���۵� �ƴ� ��� �̵�
                if(arr[next_ry][next_rx] != block && arr[next_ry][next_rx] != hole) {
                    next_ry += dy[i];
                    next_rx += dx[i];
                } else {
                    // ���� ��ġ�� ���� ���, �� ĭ �ǵ��ư��� �̵� ����(break)
                    if(arr[next_ry][next_rx] == block) {
                        next_ry -= dy[i];
                        next_rx -= dx[i];
                    }
                    break;
                }
            }
            
            while(1) {
                // ���� ��ġ�� ���� �ƴϰ� ���۵� �ƴ� ��� �̵�
                if(arr[next_by][next_bx] != block && arr[next_by][next_bx] != hole) {
                    next_by += dy[i];
                    next_bx += dx[i];
                } else {
                    // ���� ��ġ�� ���� ���, �� ĭ �ǵ��ư��� �̵� ����(break)
                    if(arr[next_by][next_bx] == block) {
                        next_by -= dy[i];
                        next_bx -= dx[i];
                    }
                    break;
                }
            }
            
            // ���� ���� �Ķ� ���� ��ġ�� ���� ���, �� ���� ������ ���� �� ĭ �ڷ� �̵�
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
            
            // ���� ��ġ�� �湮�� ���� ���� ���, ť�� ����
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

