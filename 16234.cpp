/*
 *
 *  2020.05.11
 *  https://www.acmicpc.net/problem/16234
 *
*/

#include <iostream>
#include <queue>

using namespace std;

int N;
// L <= x <= R
int L;
int R;

int** arr;
int** visited;

int dx[4] = {+1, -1, 0, 0};
int dy[4] = {0, 0, +1, -1};

// 절대값 제공하는 함수
int abs(int x, int y) {
    if(x - y < 0)
        return y - x;
    else
        return x - y;
}

// 인구 차이가 L과 R사이의 값인지 확인하는 함수
bool between(int a, int b) {
    int diff = abs(a, b);
    if(diff >= L && diff <= R)
        return true;
    else
        return false;
}

// 방문 기록을 초기화하는 함수
void init() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = 0;
        }
    }
}

int main(void) {
    int i;
    int j;
    int k;
    scanf("%d %d %d", &N, &L, &R);

    // 배열 동적 할당
    arr = (int**)malloc(sizeof(int*) * N);
    visited = (int**)malloc(sizeof(int*) * N);
    for(i = 0; i < N; i++) {
        arr[i] = (int*)malloc(sizeof(int) * N);
        visited[i] = (int*)malloc(sizeof(int) * N);
        for(j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            visited[i][j] = 0;
        }
    }
    
    int answer = 0;
    
    while(true) {
        int res = 0;
        for(i = 0; i < N; i++) {
            for(j = 0; j < N; j++) {
                queue<pair<int, int>> q;
                queue<pair<int, int>> t_q;
                bool flag = false;
                // 아직 방문하지 않은 도시인 경우
                if(visited[i][j] == 0) {
                    // 방문
                    q.push({i, j});
                    t_q.push({i, j});
                    visited[i][j] = 1;
                    
                    int sum = 0;
                    int count = 0;
                    
                    // 해당 도시에서 시작해서 모든 도시 탐색
                    while(!q.empty()) {
                        pair<int, int> tmp = q.front();
                        q.pop();
                        int _i = tmp.first;
                        int _j = tmp.second;
                        
                        // 방문한 총 인구 수 + 방문 도시 수
                        sum += arr[_i][_j];
                        count++;
                        
                        // BFS
                        for(k = 0; k < 4; k++) {
                            int new_i = _i + dx[k];
                            int new_j = _j + dy[k];
                            // 배열 안의 좌표 && 두 도시 사이의 인구수 차이가 유효한지 && 방문하지 않은 도시인지 확인
                            if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < N && visited[new_i][new_j] == 0 && between(arr[_i][_j], arr[new_i][new_j])) {
                                // 국경을 개방함
                                flag = true;
                                visited[new_i][new_j] = 1;
                                q.push({new_i, new_j});
                                // 나중에 인구 수를 평균값으로 변경하기 위해서 큐에 삽입
                                t_q.push({new_i, new_j});
                            }
                        }
                    }
                    // 국겨을 개방한 경우
                    if(flag == true) {
                        // 평균 인구 수
                        int new_pop = sum / count;
                        // 방문한 모든 도시에 대해서
                        while(!t_q.empty()) {
                            pair<int, int> tmp = t_q.front();
                            t_q.pop();
                            // 평균값으로 인구수 조정
                            arr[tmp.first][tmp.second] = new_pop;
                        }
                        // 인구 수를 조정한 경우
                        res++;
                    }
                }
            }
        }
        // 인구수를 조정한 경우, 탐색을 다시 한번 더 수행함
        if(res != 0) {
            answer++;
            // 방문 기록 초기화
            init();
        } else {
            // 더 이상 개방한 국경이 없는 경우 탐색 종료
            break;
        }
    }
    printf("%d\n", answer);
}

