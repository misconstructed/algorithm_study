/*
 *
 *  2020.02.16
 *  https://www.acmicpc.net/problem/7576
 *
 */

#include <iostream>
#include <queue>

using namespace std;

int arr[1001][1001];
int visited[1001][1001];

int max(int a, int b) {
    if(a > b) {
        return a;
    } else {
        return b;
    }
}

int main(void) {
    int M, N;
    queue<pair<int, int>> q;
    int count = 0;
    int minus = 0;
    int full = 0;
    int v = 0;
    scanf("%d %d", &M, &N);
    full = M * N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j] = 1;
            }
            if(arr[i][j] == -1) {
                minus++;
            }
        }
    }
    
    while(q.empty() != true) {
        pair<int, int> p = q.front();
        int val = visited[p.first][p.second];
        q.pop();
        v++;
        if(p.first + 1 < N) {
            if(arr[p.first+1][p.second] == 0 && visited[p.first+1][p.second] == 0) {
                q.push(make_pair(p.first+1, p.second));
                visited[p.first+1][p.second] = val + 1;
                count = max(count, visited[p.first+1][p.second]);
            }
        }
        if(p.first - 1 >= 0) {
            if(arr[p.first-1][p.second] == 0 && visited[p.first-1][p.second] == 0) {
                    q.push(make_pair(p.first-1, p.second));
                    visited[p.first-1][p.second] = val + 1;
                    count = max(count, visited[p.first-1][p.second]);
            }
        }
        if(p.second + 1 < M) {
            if(arr[p.first][p.second+1] == 0 && visited[p.first][p.second+1] == 0) {
                q.push(make_pair(p.first, p.second + 1));
                visited[p.first][p.second+1] = val + 1;
                count = max(count, visited[p.first][p.second+1]);
            }
        }
        if(p.second - 1 >= 0) {
            if(arr[p.first][p.second-1] == 0 && visited[p.first][p.second-1] == 0) {
                q.push(make_pair(p.first, p.second - 1));
                visited[p.first][p.second-1] = val + 1;
                count = max(count, visited[p.first][p.second-1]);
            }
        }
    }
    if(v == full - minus) {
        if(count > 0)
            printf("%d\n", count - 1);
        else
            printf("0\n");
    }else {
        printf("-1\n");
    }
}

