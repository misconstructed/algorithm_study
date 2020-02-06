/*
 *
 *  2020.02.06
 *  https://www.acmicpc.net/problem/1260
 *
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int arr[1001][1001] = {0, };
int visited[1001] = {0, };
int visited2[1001] = {0, };


void DFS(int N, int V) {
    if(visited[V] == 1) return;
    printf("%d ", V);
    visited[V] = 1;
    for(int i = 1; i <= N; i++) {
        if(arr[V][i] == 1) {
            if(visited[i] == 0) {
                DFS(N, i);
            }
        }
    }
}


int main(void) {
    int N, M, V;
    int start, end;
    queue<int> q;
    
    scanf("%d %d %d", &N, &M, &V);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &start, &end);
        arr[start][end] = 1;
        arr[end][start] = 1;
    }
    
    //DFS
    DFS(N, V);
    printf("\n");
    
    
    
    //BFS
    q.push(V);
    visited2[V] = 1;
    
    while(q.empty() == false) {
        int item = q.front();
        printf("%d ", item);
        q.pop();
        for(int i = 1; i <= N; i++) {
            if(arr[item][i] == 1) {
                if(visited2[i] != 1) {
                    q.push(i);
                    visited2[i] = 1;
                }
            }
        }
    }
}

