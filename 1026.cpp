/*
 *
 *  2020.03.04
 *  https://www.acmicpc.net/problem/1026
 *
 */

#include <stdio.h>

int a[50];
int b[50];
int N;

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void sort(int arr[50], int start, int end) {
    if(start >= end) return;
    int key = arr[start];
    int i = start + 1;
    int j = end;
    while(i <= j) {
        while(key > arr[i] && i <= end) i++;
        while(key <= arr[j] && j > start) j--;
        
        if(i >= j) swap(&arr[j], &arr[start]);
        else swap(&arr[i], &arr[j]);
    }
    sort(arr, start, j-1);
    sort(arr, j+1, end);
}

int main(void) {
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &b[i]);
    }
    
    sort(a, 0, N-1);
    sort(b, 0, N-1);
    
    int res = 0;
    for(int i = 0; i < N; i++) {
        res += a[i] * b[N-i-1];
    }
    printf("%d\n", res);
}

