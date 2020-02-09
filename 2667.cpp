/*
 *
 *  2020.02.09
 *  https://www.acmicpc.net/problem/2667
 *
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[27][27];
int visited[27][27];
int res[1000001];
int N;

int DFS(int x, int y) {
    if(visited[x][y] == 1) return 0;
    visited[x][y] = 1;
    int up = 0;
    int down = 0;
    int right = 0;
    int left = 0;
    if(x + 1 < N) {
        if(arr[x+1][y] == 1) {
            if(visited[x+1][y] == 0) {
                right = DFS(x+1, y);
            }
        }
    }
    if(x - 1 >= 0) {
        if(arr[x-1][y] == 1) {
            if(visited[x-1][y] == 0) {
                left = DFS(x-1, y);
            }
        }
    }
    if(y + 1 < N) {
        if(arr[x][y+1] == 1) {
            if(visited[x][y+1] == 0) {
                up = DFS(x, y+1);
            }
        }
    }
    if(y - 1 >= 0) {
        if(arr[x][y-1] == 1) {
            if(visited[x][y-1] == 0) {
                down = DFS(x, y-1);
            }
        }
    }
    return right + left + up + down + 1;
}

void sort(int* arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 1; j < size - i; j++) {
            if(arr[j-1] > arr[j]) {
                int tmp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = tmp;
            }
        }
    }
}

int main(void) {
    int tmp;
    int count = 0;
    int size;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d", &tmp);
            arr[i][j] = tmp;
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] == 1) {
                if(visited[i][j] == 0) {
                    size = DFS(i, j);
                    res[count] = size;
                    count++;
                }
            }
        }
    }
    sort(res, count);
    printf("%d\n", count);
    for(int i = 0; i < count; i++) {
        printf("%d\n", res[i]);
    }
}

