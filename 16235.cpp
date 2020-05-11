/*
 *
 *  2020.05.11
 *  https://www.acmicpc.net/problem/16235
 *  정렬하는 대상이 너무 크지 않도록 한다.
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

int n;
int m;
int k;

vector<int> map[MAX][MAX];
int input[MAX][MAX];
int energy[MAX][MAX];

bool compare(int a, int b) {
    return a < b;
}

int dx[8] = {+1, +1, +1, 0, 0, -1, -1, -1};
int dy[8] = {0, +1, -1, +1, -1, 0, +1, -1};

int main(void) {
    int i;
    int j;
    int l;
    int p;
    int u;
    int e;
    
    // 입력 받음
    scanf("%d %d %d", &n, &m, &k);
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &input[i][j]);
            energy[i][j] = 5;
        }
    }
    
    // 결과값
    int res = 0;
    
    // 나무 정보
    int x, y, age;
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &age);
        x -= 1;
        y -= 1;
        map[x][y].push_back(age);
        res++;
    }
   
    // 지정한 기간 동안
    for(i = 0; i < k; i++) {
        // 1년 주기
        for(j = 0; j < 3; j++) {
            switch(j) {
                // 봄, 여름
                case 0: {
                    // 줄어들 영양소 크기
                    int remove_sum = 0;
                    // 모든 위치에 대해서
                    for(l = 0; l < n; l++) {
                        for(p = 0; p < n; p++) {
                            // 나무가 없는 경우
                            if(map[l][p].size() == 0)
                                continue;
                            else {
                                remove_sum = 0;
                                vector<int> tmp;
                                // 나이가 어린 순서대로 정렬
                                sort(map[l][p].begin(), map[l][p].end(), compare);
                                // 모든 나무에 대해서
                                for(u = 0; u < map[l][p].size(); u++) {
                                    // 영양소가 충분이 남아있는 경우
                                    if(energy[l][p] >= map[l][p][u]) {
                                        // 영상소를 빼고, 나무 나이를 늘림
                                        energy[l][p] -= map[l][p][u];
                                        map[l][p][u]++;
                                        tmp.push_back(map[l][p][u]);
                                    } else {
                                        // 영양소가 충분하기 않은 경우, 나무 죽음
                                        remove_sum += (map[l][p][u] / 2);
                                        res--;
                                    }
                                }
                                // 죽은 나무의 나이의 반 만큼 영양소 증가
                                energy[l][p] += remove_sum;
                                map[l][p] = tmp;
                            }
                        }
                    }
                    break;
                }
                // 가을 : 번식
                case 1:
                    for(l = 0; l < n; l++) {
                        for(p = 0; p < n; p++) {
                            if(map[l][p].size() == 0)
                                continue;
                            else {
                                for(u = 0; u < map[l][p].size(); u++) {
                                    // 나무의 나이가 5의 배수인 경우
                                    if(map[l][p][u] % 5 == 0) {
                                        // 주변의 8자리에 나무 번식
                                        for(e = 0; e < 8; e++) {
                                            // 새 좌표
                                            int new_x = l + dx[e];
                                            int new_y = p + dy[e];
                                            // 유효한 좌표인 경우
                                            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                                                // 새 나무 생성
                                                map[new_x][new_y].push_back(1);
                                                res++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                // 겨울 : 영양분 추가
                case 2:
                    // 양분 추가
                    for(l = 0; l < n; l++) {
                        for(p = 0; p < n; p++) {
                            energy[l][p] += input[l][p];
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    
    printf("%d\n", res);
    return 0;
}

