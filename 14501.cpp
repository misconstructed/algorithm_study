/*
 *
 *  2020.04.01
 *  https://www.acmicpc.net/problem/14501
 *
 */

#include <stdio.h>
#include <stdlib.h>

int n;
// input value
int** input;
// next date, max value
int** max;

int main(void) {
    int i = 0;
    int j = 0;
    
    scanf("%d", &n);
    
    // memory allocation
    input = (int**)malloc(sizeof(int*) * (n+1));
    max = (int**)malloc(sizeof(int*) * (n+1));
    for(i = 0; i < n+1; i++) {
        input[i] = (int*)malloc(sizeof(int) * 2);
        // date, value
        scanf("%d %d", &input[i][0], &input[i][1]);
        
        max[i] = (int*)malloc(sizeof(int) * 2);
        for(j = 0; j < 2; j++) {
            max[i][j] = 0;
        }
    }
    
    // max date
    max[0][0] = input[0][0];
    // next value
    max[0][1] = input[0][1];
    
    // final value = 0 : if the job can't be done before you quit
    int result = 0;
    
    // if the first job can be done before you quit, the result = max[0][1];
    if(max[0][0] <= n)
        result = max[0][1];
    
    for(i = 1; i < n; i++) {
        int tmp_max = input[i][1];
        for(j = 0; j < i; j++) {
            if(max[j][0] <= i) {
                // if the job can be done before you quit (i + input[i][0] <= n)
                // if the value if bigger than max (tmp_max < max[j][1] + input[i][1])
                if(i + input[i][0] <= n && tmp_max < max[j][1] + input[i][1]) {
                    tmp_max = max[j][1] + input[i][1];
                }
            }
        }
        max[i][0] = i + input[i][0];
        max[i][1] = tmp_max;
       
        // update result
        if(max[i][0] <= n && result < max[i][1])
            result = tmp_max;
    }
    printf("%d\n", result);
}

