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

// ���밪 �����ϴ� �Լ�
int abs(int x, int y) {
    if(x - y < 0)
        return y - x;
    else
        return x - y;
}

// �α� ���̰� L�� R������ ������ Ȯ���ϴ� �Լ�
bool between(int a, int b) {
    int diff = abs(a, b);
    if(diff >= L && diff <= R)
        return true;
    else
        return false;
}

// �湮 ����� �ʱ�ȭ�ϴ� �Լ�
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

    // �迭 ���� �Ҵ�
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
                // ���� �湮���� ���� ������ ���
                if(visited[i][j] == 0) {
                    // �湮
                    q.push({i, j});
                    t_q.push({i, j});
                    visited[i][j] = 1;
                    
                    int sum = 0;
                    int count = 0;
                    
                    // �ش� ���ÿ��� �����ؼ� ��� ���� Ž��
                    while(!q.empty()) {
                        pair<int, int> tmp = q.front();
                        q.pop();
                        int _i = tmp.first;
                        int _j = tmp.second;
                        
                        // �湮�� �� �α� �� + �湮 ���� ��
                        sum += arr[_i][_j];
                        count++;
                        
                        // BFS
                        for(k = 0; k < 4; k++) {
                            int new_i = _i + dx[k];
                            int new_j = _j + dy[k];
                            // �迭 ���� ��ǥ && �� ���� ������ �α��� ���̰� ��ȿ���� && �湮���� ���� �������� Ȯ��
                            if(new_i >= 0 && new_i < N && new_j >= 0 && new_j < N && visited[new_i][new_j] == 0 && between(arr[_i][_j], arr[new_i][new_j])) {
                                // ������ ������
                                flag = true;
                                visited[new_i][new_j] = 1;
                                q.push({new_i, new_j});
                                // ���߿� �α� ���� ��հ����� �����ϱ� ���ؼ� ť�� ����
                                t_q.push({new_i, new_j});
                            }
                        }
                    }
                    // ������ ������ ���
                    if(flag == true) {
                        // ��� �α� ��
                        int new_pop = sum / count;
                        // �湮�� ��� ���ÿ� ���ؼ�
                        while(!t_q.empty()) {
                            pair<int, int> tmp = t_q.front();
                            t_q.pop();
                            // ��հ����� �α��� ����
                            arr[tmp.first][tmp.second] = new_pop;
                        }
                        // �α� ���� ������ ���
                        res++;
                    }
                }
            }
        }
        // �α����� ������ ���, Ž���� �ٽ� �ѹ� �� ������
        if(res != 0) {
            answer++;
            // �湮 ��� �ʱ�ȭ
            init();
        } else {
            // �� �̻� ������ ������ ���� ��� Ž�� ����
            break;
        }
    }
    printf("%d\n", answer);
}

