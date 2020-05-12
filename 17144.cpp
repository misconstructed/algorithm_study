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

// 세로
int r;
// 가로
int c;
// 시간
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
    // 메모리 할당
    map = (int**)malloc(sizeof(int*) * r);
    spread = (int**)malloc(sizeof(int*) * r);
    for(i = 0; i < r; i++) {
        map[i] = (int*)malloc(sizeof(int) * c);
        spread[i] = (int*)malloc(sizeof(int) * c);
        for(j = 0; j < c; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == -1) {
                // 공기청정기의 위치
                if(flag == 1) {
                    // 위 공기청정기
                    up.x = j;
                    up.y = i;
                    flag = 0;
                } else {
                    // 아래 공기청정기
                    down.x = j;
                    down.y = i;
                }
            }
        }
    }
    
    // t 시간에 대해
    while(t > 0) {
        // spread 초기화
        for(i = 0; i < r; i++) {
            for(j = 0; j < c; j++) {
                spread[i][j] = 0;
            }
        }
        
        for(i = 0; i < 2; i++) {
            switch(i){
                // spread
                case 0: {
                    // 모든 좌표에 대해서
                    for(j = 0; j < r; j++) {
                        for(k = 0; k < c; k++) {
                            if(map[j][k] != -1) {
                                // 전파될 먼지
                                int s = map[j][k] / 5;
                                // 전파된 방향 개수
                                int count = 0;
                                // 상, 하, 좌, 우로 먼지 전파
                                for(l = 0; l < 4; l++) {
                                    int new_x = k + dx[l];
                                    int new_y = j + dy[l];
                                    // 유효한 좌표인 경우
                                    if(new_x >= 0 && new_x < c && new_y >= 0 && new_y < r) {
                                        if(map[new_y][new_x] != -1) {
                                            spread[new_y][new_x] += s;
                                            count++;
                                        }
                                    }
                                }
                                // 퍼진만큼 감소
                                map[j][k] -= count * s;
                            }
                        }
                    }
                    
                    // 미세먼지 전파
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

