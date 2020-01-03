/*
 *
 *  2020.01.03
 *  https://www.acmicpc.net/problem/11054
 *
*/

#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[1001] = {0};
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int asc_len[1001] = {0};
    int desc_len[1001] = {0};
    
    asc_len[0] = 1;
    desc_len[n-1] = 1;
    
    for(int i = 0; i < n; i++) {
        int max = -1;
        int index = -1;
        for(int j = i-1; j >= 0; j--) {
            if(arr[i] > arr[j]) {
                if(max < asc_len[j]) {
                    max = asc_len[j];
                    index = j;
                }
            }
        }
        if(index == -1) {
            asc_len[i] = 1;
        } else {
            asc_len[i] = max + 1;
        }
    }
    
    for(int i = n-1; i >= 0; i--) {
        int max = -1;
        int index = -1;
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                if(max < desc_len[j]) {
                    max = desc_len[j];
                    index = j;
                }
            }
        }
        if(index == -1) {
            desc_len[i] = 1;
        } else {
            desc_len[i] = max + 1;
        }
    }
    
    int res = -1;
    for(int i = 0; i < n; i++) {
        int tmp = asc_len[i] + desc_len[i] - 1;
        if(res < tmp) res = tmp;
    }
    printf("%d\n", res);
}

