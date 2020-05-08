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

// ���밪 ���ϱ�
int abs(int x, int y) {
    int res = x - y;
    if(res < 0)
        return (-1) * res;
    else return res;
}

void search(int count, int start) {
    // M���� ġŲ���� ��� �� ���
    if(count == M) {
        int local_min = 0;
        // ��� ���� ���ؼ� ���� ����� ġŲ���� �Ÿ��� ����
        for(int i = 0; i < one.size(); i++) {
            int two_min = 999999;
            // ������ ġŲ���� ���� �Ÿ� ���ϱ�
            for(int j = 0; j < s.size(); j++) {
                int dist = abs(s[j].first, one[i].first) + abs(s[j].second, one[i].second);
                if(dist < two_min)
                    two_min = dist;
            }
            local_min += two_min;
        }
        // �ּ� �Ÿ��� ��� ��������� ����
        if(local_min < res)
            res = local_min;
        return;
    }
    
    for(int i = start; i < two.size(); i++) {
        // �湮���� ���� ���
        if(arr[two[i].second][two[i].first] != 1) {
            arr[two[i].second][two[i].first] = 1;
            s.push_back(two[i]);
            // ���� ġŲ�� Ž��
            search(count + 1, i + 1);
            // ���󺹱�
            s.pop_back();
            arr[two[i].second][two[i].first] = 0;
        }
    }
}

int main(void) {
    int i, j;
    scanf("%d %d", &N, &M);
    // �޸� �Ҵ�
    arr = (int**)malloc(sizeof(int*) * N);
    visited = (int**)malloc(sizeof(int*) * N);
    
    // �� �Է�
    for(i = 0; i < N; i++){
        arr[i] = (int*)malloc(sizeof(int) * N);
        visited[i] = (int*)malloc(sizeof(int) * N);
        
        for(j = 0; j < N; j++) {
            scanf("%d", &arr[i][j]);
            if(arr[i][j] == 1) {
                // ���� ���
                one.push_back({j, i});
            } else if(arr[i][j] == 2) {
                // ġŲ���� ���
                two.push_back({j, i});
            }
        }
    }
    
    res = 999999;
    // Ž��
    search(0, 0);
    printf("%d\n", res);
}

