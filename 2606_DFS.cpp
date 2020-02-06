/*
 *
 *  2020.02.06
 *  https://www.acmicpc.net/problem/2606
 *
 */

#include <iostream>

using namespace std;

int arr[102][102] = {0, };
int visited[102] = {0, };


void DFS(int N, int v, int* count) {
    if(visited[v] == 1) return;
    *count = *count + 1;
    visited[v] = 1;
    for(int i = 1; i <= N; i++) {
        if(arr[v][i] == 1) {
            if(visited[i] == 0) {
                DFS(N, i, count);
            }
        }
    }
}


int main(void) {
    int N, M, start, end;
    scanf("%d", &N);
    scanf("%d", &M);
    int count = 0;
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &start, &end);
        arr[start][end] = 1;
        arr[end][start] = 1;
    }
    int v = 1;
    DFS(N, v, &count);
    
    printf("%d\n", count-1);
    
}

