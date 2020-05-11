/*
 *
 *  2020.05.11
 *  https://www.acmicpc.net/problem/16235
 *  �����ϴ� ����� �ʹ� ũ�� �ʵ��� �Ѵ�.
 * 
*/

#include <iostream>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

int n;
int m;
int k;

vector<int> map[MAX][MAX];
int input[MAX][MAX];
int energy[MAX][MAX];

bool compare(int a, int b) {
    return a < b;
}

int dx[8] = {+1, +1, +1, 0, 0, -1, -1, -1};
int dy[8] = {0, +1, -1, +1, -1, 0, +1, -1};

int main(void) {
    int i;
    int j;
    int l;
    int p;
    int u;
    int e;
    
    // �Է� ����
    scanf("%d %d %d", &n, &m, &k);
    
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &input[i][j]);
            energy[i][j] = 5;
        }
    }
    
    // �����
    int res = 0;
    
    // ���� ����
    int x, y, age;
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &x, &y, &age);
        x -= 1;
        y -= 1;
        map[x][y].push_back(age);
        res++;
    }
   
    // ������ �Ⱓ ����
    for(i = 0; i < k; i++) {
        // 1�� �ֱ�
        for(j = 0; j < 3; j++) {
            switch(j) {
                // ��, ����
                case 0: {
                    // �پ�� ����� ũ��
                    int remove_sum = 0;
                    // ��� ��ġ�� ���ؼ�
                    for(l = 0; l < n; l++) {
                        for(p = 0; p < n; p++) {
                            // ������ ���� ���
                            if(map[l][p].size() == 0)
                                continue;
                            else {
                                remove_sum = 0;
                                vector<int> tmp;
                                // ���̰� � ������� ����
                                sort(map[l][p].begin(), map[l][p].end(), compare);
                                // ��� ������ ���ؼ�
                                for(u = 0; u < map[l][p].size(); u++) {
                                    // ����Ұ� ����� �����ִ� ���
                                    if(energy[l][p] >= map[l][p][u]) {
                                        // ����Ҹ� ����, ���� ���̸� �ø�
                                        energy[l][p] -= map[l][p][u];
                                        map[l][p][u]++;
                                        tmp.push_back(map[l][p][u]);
                                    } else {
                                        // ����Ұ� ����ϱ� ���� ���, ���� ����
                                        remove_sum += (map[l][p][u] / 2);
                                        res--;
                                    }
                                }
                                // ���� ������ ������ �� ��ŭ ����� ����
                                energy[l][p] += remove_sum;
                                map[l][p] = tmp;
                            }
                        }
                    }
                    break;
                }
                // ���� : ����
                case 1:
                    for(l = 0; l < n; l++) {
                        for(p = 0; p < n; p++) {
                            if(map[l][p].size() == 0)
                                continue;
                            else {
                                for(u = 0; u < map[l][p].size(); u++) {
                                    // ������ ���̰� 5�� ����� ���
                                    if(map[l][p][u] % 5 == 0) {
                                        // �ֺ��� 8�ڸ��� ���� ����
                                        for(e = 0; e < 8; e++) {
                                            // �� ��ǥ
                                            int new_x = l + dx[e];
                                            int new_y = p + dy[e];
                                            // ��ȿ�� ��ǥ�� ���
                                            if(new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                                                // �� ���� ����
                                                map[new_x][new_y].push_back(1);
                                                res++;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                // �ܿ� : ����� �߰�
                case 2:
                    // ��� �߰�
                    for(l = 0; l < n; l++) {
                        for(p = 0; p < n; p++) {
                            energy[l][p] += input[l][p];
                        }
                    }
                    break;
                default:
                    break;
            }
        }
    }
    
    printf("%d\n", res);
    return 0;
}

