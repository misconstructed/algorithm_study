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
    
    scanf("%d", &N);    // N 입력
    for(i = 0; i < N; i++) {
        scanf("%d", &input);
        total += input;     // 전체 입력값의 합 (산술평균에 사용)
        
        // 최빈값 구하기
        count_tmp = ++count[SIZE + input];
        if(count_tmp > count_max) count_max = count_tmp;
        
        // 최대, 최소값 구하기
        if(i == 0) {
            min = input;
            max = input;
        } else {
            if(min > input) min = input;
            if(max < input) max = input;
        }
        v.push_back(input);
    }
    
    // 산술평균 출력
    avg = getAverage(total, N);
    printf("%d\n", avg);
    
    // 중앙값 출력
    mid = getMid(v, N);
    printf("%d\n", mid);
    
    // 최빈값 출력
    count_res = getCount(count, count_max);
    printf("%d\n", count_res);
    
    // 범위 (최댓값과 최솟값의 차이)
    range = getRange(min, max);
    printf("%d\n", range);
    
}

// 산술평균 구하기
int getAverage(int total, int N) {
    double half = 0.5;
    double mhalf = -0.5;
    int mod = total % N;
    int div = total / N;
    double res = (double)mod / N;
    // 양수인 경우
    if(res > 0) {
        if(res >= half) {
            div++;
        }
    // 음수인 경우
    } else {
        if(res <= mhalf) {
            div--;
        }
    }
    
    return div;
}

// 중앙값 구하기
int getMid(vector<int> v, int N) {
    sort(v.begin(), v.end());
    int index = N / 2;
    int res = v[index];
    return res;
}

// 범위 구하기
int getRange(int min, int max) {
    return max - min;
}

// 최빈값 구하기
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

