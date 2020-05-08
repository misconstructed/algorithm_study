/*
 *
 *  2020.05.08
 *  https://www.acmicpc.net/problem/15686
 *
*/

#include <iostream>
#include <vector>

using namespace std;

int N;
int M;
int** arr;
int** visited;
int res;
vector<pair<int, int>> one;
vector<pair<int, int>> two;
vector<pair<int, int>> s;

// 절대값 구하기
int abs(int x, int y) {
    int res = x - y;
    if(res < 0)
        return (-1) * res;
    else return res;
}

void search(int count, int start) {
    // M개의 치킨집을 모두 고른 경우
    if(count == M) {
        int local_min = 0;
        // 모든 집에 대해서 가장 가까운 치킨집의 거리를 구함
        for(int i = 0; i < one.size(); i++) {
            int two_min = 999999;
            // 선택한 치킨집에 대한 거리 구하기
            for(int j = 0; j < s.size(); j++) {
                int dist = abs(s[j].first, one[i].first) + abs(s[j].second, one[i].second);
                if(dist < two_min)
                    two_min = dist;
            }
            local_min += two_min;
        }
        // 최소 거리인 경우 결과값으로 지정
        if(local_min < res)
            res = local_min;
        return;
    }
    
    for(int i = start; i < two.size(); i++) {
        // 방문하지 않은 경우
        if(arr[two[i].second][two[i].first] != 1) {
            arr[two[i].second][two[i].first] = 1;
            s.push_back(two[i]);
            // 다음 치킨집 탐색
            search(count + 1, i + 1);
            // 원상복귀
            s.pop_back();
            arr[two[i].second][two[i].first] = 0;
        }
    }
}

int main(void) {
    int i, j;
    scanf("%d %d", &N, &M);
    // 메모리 할당
    arr = (int**)malloc(sizeof(int*) * N);
    visited = (int**)malloc(sizeof(int*) * N);
    
    // 값 입력
    for(i = 0; i < N; i++){
        arr[i] = (int*)malloc(sizeof(int) * N);
        visited[i] = (int*)malloc(sizeof(int) * N);
        
        for(j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) {
                // 집인 경우
                one.push_back({j, i});
            } else if(arr[i][j] == 2) {
                // 치킨집인 경우
                two.push_back({j, i});
            }
        }
    }
    
    res = 999999;
    // 탐색
    search(0, 0);
    printf("%d\n", res);
}

