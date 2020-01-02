/*
 *
 *  2020.01.02
 *  https://www.acmicpc.net/problem/11053
 *
*/

#include <stdio.h>

int main(void) {
    int n = 0;
    scanf("%d", &n);
    
    int arr[1001] = {0};
    int len[1001] = {0};
    int top[1001] = {0};
    int max = -1;
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    len[0] = 1;
    top[0] = arr[0];
    max = 1;
    for(int i = 1; i < n; i++) {
        int index = -1;
        for(int j = i - 1; j >= 0; j--) {
            if(top[j] < arr[i]) {
                if(index == -1) {
                    index = j;
                } else if(len[j] > len[index]) {
                    index = j;
                }
            }
        }
        if(index == -1) {
            len[i] = 1;
            top[i] = arr[i];
        } else {
            top[i] = arr[i];
            len[i] = len[index] + 1;
        }
        
        if(max < len[i]) max = len[i];
    }
    
    printf("%d\n", max);
    
}

