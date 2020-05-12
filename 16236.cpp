/*
 *
 *  2020.05.12
 *  https://www.acmicpc.net/problem/16236
 *
*/

#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

typedef struct _point {
    int x;
    int y;
    int dist;
} point;

point shark_point;

int n;
int** map;
int** visited;
int age;
int eat;
int fish_count;
int res;

int dx[4] = {0, -1, +1, 0};
int dy[4] = {-1, 0, 0, +1};

// 비교 : 이동거리가 짧은 경우 < y좌표가 작은 경우 < x좌표가 작은 경우
bool compare(point a, point b) {
    if(a.dist < b.dist) {
        return a.dist < b.dist;
    } else if(a.dist == b.dist){
        if(a.y < b.y) {
            return a.y < b.y;
        } else if(a.y == b.y){
            return a.x < b.x;
        } else {
            return a.y < b.y;
        }
    } else {
        return a.dist < b.dist;
    }
}

int main(void) {
    int i, j;
    scanf("%d", &n);
    
    // 아기 상어의 처음 나이 = 2
    age = 2;
    // 아기 상어가 먹은 물고기 수 = 0
    eat = 0;
    // 전체 소요 시간 = 0
    res = 0;
    
    // 메모리 할당
    visited = (int**)malloc(sizeof(int*) * n);
    map = (int**)malloc(sizeof(int*) * n);
    for(i = 0; i < n; i++) {
        map[i] = (int*)malloc(sizeof(int) * n);
        visited[i] = (int*)malloc(sizeof(int) * n);
        for(j = 0; j < n; j++) {
            visited[i][j] = 0;
            scanf("%d", &map[i][j]);
            if(map[i][j] == 9) {
                shark_point.x = j;
                shark_point.y = i;
                shark_point.dist = 0;
                map[i][j] = 0;
            } else if(map[i][j] != 0) {
                // 물고기 개수
                fish_count++;
            }
        }
    }
    
    while(fish_count > 0) {
        int flag = 0;
        // visited 초기화
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = 0;
            }
        }
        deque<point> q;
        q.push_back(shark_point);
        visited[shark_point.y][shark_point.x] = 1;
        
        while(q.size() != 0) {
            point p = q.front();
            q.pop_front();
            
            int x = p.x;
            int y = p.y;
            
            // 먹을 수 있는 경우
            if(map[y][x] != 0 && map[y][x] < age) {
                map[y][x] = 0;
                eat++;
                fish_count--;
                // 먹은 물고기 개수 == 나이 인 경우, 나이 증가
                if(eat == age) {
                    age++;
                    eat = 0;
                }
                // 전체 이동 거리(시간) 증가
                res += p.dist;
                // 새로 출발하는 위치 변경
                shark_point.x = x;
                shark_point.y = y;
                flag = 1;
                break;
            }
            
            // 상하좌우 이동
            for(i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                // 유효한 좌표인 경우
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                    // 방문하지 않고 && 자신의 나이보다 같거나 어린 경우
                    if(visited[new_y][new_x] == 0 && map[new_y][new_x] <= age) {
                        q.push_back({new_x, new_y, p.dist + 1});
                        visited[new_y][new_x] = 1;
                    }
                }
            }
            // 기준에 맞에 정렬
            sort(q.begin(), q.end(), compare);
        }
        // 먹을 수 있는 (먹은) 물고기가 하나도 없는 경우 탐색 종료
        if(flag == 0)
            break;
    }
    printf("%d\n", res);
}

