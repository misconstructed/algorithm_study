/*
 *
 *  2020.03.30
 *  https://www.acmicpc.net/problem/13458
 *
 */

#include <stdio.h>
#include <stdlib.h>

int N;
int* A;
int B;
int C;
long long int result;

int main(void) {
    int i = 0;
    int tmp = 0;
    long long int count = 0;
    scanf("%d", &N);
    A = (int*) malloc(sizeof(int) * N);
    for(i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }
    scanf("%d %d", &B, &C);
    for(i = 0; i < N; ++i) {
        tmp = A[i];
        count = 0;
        // no student
        if(tmp == 0) {
            count = 0;
        } else {
            count = 1;
            if(tmp > B) {
                // use first teacher
                tmp = tmp - B;
                
                // use second teacher
                if(tmp % C == 0) {
                    count += tmp / C;
                } else {
                    count += (tmp / C + 1);
                }
            }
        }
        result += count;
    }
    printf("%lld\n", result);
}

