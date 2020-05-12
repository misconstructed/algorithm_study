/*
 *
 *  2020.05.12
 *  https://www.acmicpc.net/problem/17144
 *
*/

#include <iostream>

using namespace std;

typedef struct _a{
    int x;
    int y;
} point;

point up;
point down;

// ����
int r;
// ����
int c;
// �ð�
int t;

int** map;
int** spread;

int dx[4] = {+1, 0, -1, 0};
int dy[4] = {0, +1, 0, -1};

int main(void) {
    int i;
    int j;
    int k;
    int l;
    
    int flag = 1;
    
    scanf("%d %d %d", &r, &c, &t);
    // �޸� �Ҵ�
    map = (int**)malloc(sizeof(int*) * r);
    spread = (int**)malloc(sizeof(int*) * r);
    for(i = 0; i < r; i++) {
        map[i] = (int*)malloc(sizeof(int) * c);
        spread[i] = (int*)malloc(sizeof(int) * c);
        for(j = 0; j < c; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == -1) {
                // ����û������ ��ġ
                if(flag == 1) {
                    // �� ����û����
                    up.x = j;
                    up.y = i;
                    flag = 0;
                } else {
                    // �Ʒ� ����û����
                    down.x = j;
                    down.y = i;
                }
            }
        }
    }
    
    // t �ð��� ����
    while(t > 0) {
        // spread �ʱ�ȭ
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                spread[i][j] = 0;
            }
        }
        
        for(i = 0; i < 2; i++) {
            switch(i){
                // spread
                case 0: {
                    // ��� ��ǥ�� ���ؼ�
                    for(j = 0; j < r; j++) {
                        for(k = 0; k < c; k++) {
                            if(map[j][k] != -1) {
                                // ���ĵ� ����
                                int s = map[j][k] / 5;
                                // ���ĵ� ���� ����
                                int count = 0;
                                // ��, ��, ��, ��� ���� ����
                                for(l = 0; l < 4; l++) {
                                    int new_x = k + dx[l];
                                    int new_y = j + dy[l];
                                    // ��ȿ�� ��ǥ�� ���
                                    if(new_x >= 0 && new_x < c && new_y >= 0 && new_y < r) {
                                        if(map[new_y][new_x] != -1) {
                                            spread[new_y][new_x] += s;
                                            count++;
                                        }
                                    }
                                }
                                // ������ŭ ����
                                map[j][k] -= count * s;
                            }
                        }
                    }
                    
                    // �̼����� ����
                    for(j = 0; j < r; j++) {
                        for(k = 0; k < c; k++) {
                            map[j][k] += spread[j][k];
                        }
                    }
                    break;
                }
                    
                // clean
            case 1: {
                    int x;
                    int y;
                    // up
                    x = up.x;
                    y = up.y;
                    while(y > 0) {
                        if(map[y][x] != -1) {
                            map[y][x] = map[y-1][x];
                        }
                        y--;
                    }
                    while(x < c-1) {
                        map[y][x] = map[y][x+1];
                        x++;
                    }
                    while(y < up.y) {
                        map[y][x] = map[y+1][x];
                        y++;
                    }
                    while(x > 0) {
                        if(map[y][x-1] != -1) {
                            map[y][x] = map[y][x-1];
                        } else {
                            map[y][x] = 0;
                        }
                        x--;
                    }
                    // down
                    x = down.x;
                    y = down.y;
                    
                    while(y < r-1) {
                        if(map[y][x] != -1) {
                            map[y][x] = map[y+1][x];
                        }
                        y++;
                    }
                    while(x < c-1) {
                        map[y][x] = map[y][x+1];
                        x++;
                    }
                    
                    while(y > down.y) {
                        map[y][x] = map[y-1][x];
                        y--;
                    }
                    while(x > 0) {
                        if(map[y][x-1] != -1) {
                            map[y][x] = map[y][x-1];
                        } else {
                            map[y][x] = 0;
                        }
                        x--;
                    }
                    break;
                }
            }
        }
        --t;
    }
    int res = 0;
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            if(map[i][j] != 0 && map[i][j] != -1) {
                res += map[i][j];
            }
        }
    }
    printf("%d\n", res);
}

