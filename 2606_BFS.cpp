/*
 *
 *  2020.02.06
 *  https://www.acmicpc.net/problem/2606
 *
 */

#include <iostream>
#include <stack>

using namespace std;

int arr[102][102] = {0, };
int visited[102] = {0, };

int main(void) {
    int N, M, start, end;
    stack<int> s;
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 0; i < M; i++) {
        scanf("%d %d", &start, &end);
        arr[start][end] = 1;
        arr[end][start] = 1;
    }
    int count = 0;
    int v = 1;
    s.push(v);
    visited[v] = 1;
    while(s.empty() == false) {
        v = s.top();
        s.pop();
        for(int i = 1; i <= N; i++) {
            if(arr[v][i] == 1) {
                if(visited[i] == 0) {
                    visited[i] = 1;
                    count++;
                    s.push(i);
                }
            }
        }
    }
    printf("%d\n", count);
    
}

