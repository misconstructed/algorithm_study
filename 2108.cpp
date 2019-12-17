/*
 *
 *  2019.12.18
 *  https://www.acmicpc.net/problem/2108
 *
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int getAverage(int, int);
int getMid(vector<int>, int);
int getRange(int, int);
int getCount(int*, int);

int main(void) {
    int SIZE = 4000;
    int N;
    int i;
    int input;
    int total = 0;
    int count[8002] = {0, };
    int avg = 0;
    int min = 0;
    int max = 0;
    int range;
    int count_tmp;
    int count_max = 0;
    int count_res;
    vector <int> v;
    int mid;
    
    scanf("%d", &N);    // N �Է�
    for(i = 0; i < N; i++) {
        scanf("%d", &input);
        total += input;     // ��ü �Է°��� �� (�����տ� ���)
        
        // �ֺ� ���ϱ�
        count_tmp = ++count[SIZE + input];
        if(count_tmp > count_max) count_max = count_tmp;
        
        // �ִ�, �ּҰ� ���ϱ�
        if(i == 0) {
            min = input;
            max = input;
        } else {
            if(min > input) min = input;
            if(max < input) max = input;
        }
        v.push_back(input);
    }
    
    // ������ ���
    avg = getAverage(total, N);
    printf("%d\n", avg);
    
    // �߾Ӱ� ���
    mid = getMid(v, N);
    printf("%d\n", mid);
    
    // �ֺ� ���
    count_res = getCount(count, count_max);
    printf("%d\n", count_res);
    
    // ���� (�ִ񰪰� �ּڰ��� ����)
    range = getRange(min, max);
    printf("%d\n", range);
    
}

// ������ ���ϱ�
int getAverage(int total, int N) {
    double half = 0.5;
    double mhalf = -0.5;
    int mod = total % N;
    int div = total / N;
    double res = (double)mod / N;
    // ����� ���
    if(res > 0) {
        if(res >= half) {
            div++;
        }
    // ������ ���
    } else {
        if(res <= mhalf) {
            div--;
        }
    }
    
    return div;
}

// �߾Ӱ� ���ϱ�
int getMid(vector<int> v, int N) {
    sort(v.begin(), v.end());
    int index = N / 2;
    int res = v[index];
    return res;
}

// ���� ���ϱ�
int getRange(int min, int max) {
    return max - min;
}

// �ֺ� ���ϱ�
int getCount(int* count, int max) {
    int check = false;
    int res = 0;
    int SIZE = 4000;
    for(int i = 0; i < SIZE * 2 + 1; i++) {
        if(count[i] == max) {
            if(check == false) {
                res = i - SIZE;
                check = true;
            } else {
                res = i - SIZE;
                return res;
            }
        }
    }
    return res;
}

