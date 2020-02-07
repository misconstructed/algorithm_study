/*
 *
 *  2020.02.07
 *  https://www.acmicpc.net/problem/1012
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[52][52] ;
int visited[52][52];
int N;
int M;
int back = -1;
int front = 1;

void dfs(int x, int y) {
    if(visited[x][y] == 1) return;
    visited[x][y] = 1;
    if(x + front < M ){
        if(arr[x+front][y] == 1){
            dfs(x+front, y);
        }
    }
    if(x + back >= 0) {
        if(arr[x+back][y] == 1){
            dfs(x+back, y);
        }
    }
    if(y + back >= 0) {
        if(arr[x][y+back] == 1){
            dfs(x, y+back);
        }
    }
    if(y + front < N) {
        if(arr[x][y+front] == 1){
            dfs(x, y+front);
        }
    }
}

int main(void) {
    int T,  K;
    int start, end;
    scanf("%d", &T);
    int* res = (int*)malloc(sizeof(int) * (T+1));
    for(int i = 0; i < T; i++) {
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        scanf("%d %d %d", &M, &N, &K);
        for(int j = 0; j < K; j++) {
            scanf("%d %d", &start, &end);
            arr[start][end] = 1;
        }
        int count = 0;
        for(int j = 0; j < M; j++) {
            for(int k = 0; k < N; k++) {
                if(arr[j][k] == 1 && visited[j][k] == 0) {
                    dfs(j, k);
                    count++;
                }
            }
        }
        res[i] = count;
    }
    for(int i = 0; i < T; i++) {
        printf("%d\n", res[i]);
    }
}


