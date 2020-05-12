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

// �� : �̵��Ÿ��� ª�� ��� < y��ǥ�� ���� ��� < x��ǥ�� ���� ���
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
    
    // �Ʊ� ����� ó�� ���� = 2
    age = 2;
    // �Ʊ� �� ���� ����� �� = 0
    eat = 0;
    // ��ü �ҿ� �ð� = 0
    res = 0;
    
    // �޸� �Ҵ�
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
                // ����� ����
                fish_count++;
            }
        }
    }
    
    while(fish_count > 0) {
        int flag = 0;
        // visited �ʱ�ȭ
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
            
            // ���� �� �ִ� ���
            if(map[y][x] != 0 && map[y][x] < age) {
                map[y][x] = 0;
                eat++;
                fish_count--;
                // ���� ����� ���� == ���� �� ���, ���� ����
                if(eat == age) {
                    age++;
                    eat = 0;
                }
                // ��ü �̵� �Ÿ�(�ð�) ����
                res += p.dist;
                // ���� ����ϴ� ��ġ ����
                shark_point.x = x;
                shark_point.y = y;
                flag = 1;
                break;
            }
            
            // �����¿� �̵�
            for(i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];
                // ��ȿ�� ��ǥ�� ���
                if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                    // �湮���� �ʰ� && �ڽ��� ���̺��� ���ų� � ���
                    if(visited[new_y][new_x] == 0 && map[new_y][new_x] <= age) {
                        q.push_back({new_x, new_y, p.dist + 1});
                        visited[new_y][new_x] = 1;
                    }
                }
            }
            // ���ؿ� �¿� ����
            sort(q.begin(), q.end(), compare);
        }
        // ���� �� �ִ� (����) ����Ⱑ �ϳ��� ���� ��� Ž�� ����
        if(flag == 0)
            break;
    }
    printf("%d\n", res);
}

