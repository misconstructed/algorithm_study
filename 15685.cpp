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

// �̵� ����
int dx[4] = {+1, 0, -1, 0};
int dy[4] = {0, -1, 0, +1};
// �湮 ���� üũ, 0���� �ʱ�ȭ
int arr[101][101];

// �ð�������� ȸ��(�߽�, ȸ���Ϸ��� ��ǥ)
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
    
    // ũ�� �Է�
    scanf("%d", &N);
    
    for(i = 0; i < N; i++) {
        // ��ǥ�� �Է�
        scanf("%d %d %d %d", &x, &y, &d, &g);
        queue<pair<int, int>> q;
        // �����
        q.push({x, y});
        arr[y][x] = 1;
        // �̵�
        end.first = x + dx[d];
        end.second = y + dy[d];
        
        // 0����
        q.push({end.first, end.second});
        arr[end.second][end.first] = 1;
        
        // ���븸ŭ �ݺ�
        for(j = 0; j < g; j++) {
            size = q.size();

            pair<int, int> tmp_end;
            for(k = 0; k < size; k++) {
                pair<int, int> tmp = q.front();
                // ���� ���� ��Ҹ� ���� �ڿ� �ٽ� �߰�
                q.pop();
                q.push(tmp);
                
                // ȸ���ϴ� �߽� ��ǥ�� �ƴ� ��ǥ�鿡 ���ؼ� ȸ��
                if(!(tmp.first == end.first && tmp.second == end.second)) {
                    // ȸ���� ���ο� ��ǥ
                    pair<int, int> new_point = rotate(end, tmp);
                    
                    // ȸ���� ��ġ �߰� (��ǥ�� ��ȿ�� ���)
                    if(new_point.first >= 0 && new_point.first <= 100 && new_point.second >= 0 && new_point.second <= 100) {
                        // �湮���� ���� ���, �湮���� �߰�
                        q.push(new_point);
                        arr[new_point.second][new_point.first] = 1;
                        
                        // ������� ȸ���ؼ� ������ ���ο� ���� ��������� ���� �ָ� ��ġ�ϴ� ��ǥ
                        // �׷��Ƿ� ������ ȸ���ϴ� ��� �߽��� ��
                        if(tmp.first == x && tmp.second == y)
                            tmp_end = new_point;
                    }
                }
            }
            // ȸ���ϴ� �߽� ��ǥ�� ����
            end = tmp_end;
        }
    }
    int res = 0;
    for(i = 0; i < 100; i++) {
        for(j = 0; j < 100; j++) {
            // 4�������� ��� �湮�� ��� ����� �߰�
            if(arr[j][i] == 1 && arr[j+1][i] == 1 && arr[j][i+1] == 1 && arr[j+1][i+1] == 1)
                ++res;
        }
    }
    printf("%d\n", res);
}

