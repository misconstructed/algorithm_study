/*
 *
 *  2020.05.08
 *  https://www.acmicpc.net/problem/15685
 *
*/

#include <iostream>
#include <queue>
#include <set>

using namespace std;

// 이동 방향
int dx[4] = {+1, 0, -1, 0};
int dy[4] = {0, -1, 0, +1};
// 방문 여부 체크, 0으로 초기화
int arr[101][101];

// 시계방향으로 회전(중심, 회전하려는 좌표)
pair<int, int> rotate(pair<int, int> org, pair<int, int> target) {
    int new_x = org.first + org.second - target.second;
    int new_y = org.second - org.first + target.first;
    return {new_x, new_y};
}

int main(void) {
    int N;
    int x;
    int y;
    int d;
    int g;
    int i, j, k;
    int size;
    pair<int,int> end;
    
    // 크기 입력
    scanf("%d", &N);
    
    for(i = 0; i < N; i++) {
        // 좌표값 입력
        scanf("%d %d %d %d", &x, &y, &d, &g);
        queue<pair<int, int>> q;
        // 출발점
        q.push({x, y});
        arr[y][x] = 1;
        // 이동
        end.first = x + dx[d];
        end.second = y + dy[d];
        
        // 0세대
        q.push({end.first, end.second});
        arr[end.second][end.first] = 1;
        
        // 세대만큼 반복
        for(j = 0; j < g; j++) {
            size = q.size();

            pair<int, int> tmp_end;
            for(k = 0; k < size; k++) {
                pair<int, int> tmp = q.front();
                // 제일 앞의 요소를 제일 뒤에 다시 추가
                q.pop();
                q.push(tmp);
                
                // 회전하는 중심 좌표가 아닌 좌표들에 대해서 회전
                if(!(tmp.first == end.first && tmp.second == end.second)) {
                    // 회전한 새로운 좌표
                    pair<int, int> new_point = rotate(end, tmp);
                    
                    // 회전한 위치 추가 (좌표가 유효한 경우)
                    if(new_point.first >= 0 && new_point.first <= 100 && new_point.second >= 0 && new_point.second <= 100) {
                        // 방문하지 않은 경우, 방문으로 추가
                        q.push(new_point);
                        arr[new_point.second][new_point.first] = 1;
                        
                        // 출발점이 회전해서 생성된 새로운 값은 출발점에서 가장 멀리 위치하는 좌표
                        // 그러므로 다음에 회전하는 경우 중심이 됨
                        if(tmp.first == x && tmp.second == y)
                            tmp_end = new_point;
                    }
                }
            }
            // 회전하는 중심 좌표를 변경
            end = tmp_end;
        }
    }
    int res = 0;
    for(i = 0; i < 100; i++) {
        for(j = 0; j < 100; j++) {
            // 4꼭지점을 모두 방문한 경우 결과에 추가
            if(arr[j][i] == 1 && arr[j+1][i] == 1 && arr[j][i+1] == 1 && arr[j+1][i+1] == 1)
                ++res;
        }
    }
    printf("%d\n", res);
}

