/*
 *
 *  2019.12.18
 *  https://www.acmicpc.net/problem/2750
 *  USING QUICK SORT
 *
*/

#include <stdio.h>

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void quick(int* arr, int start, int end) {
    if(start >= end) return;
    int key = arr[start];
    int i = start + 1;
    int j = end;
    while(i <= j) {
        while(key > arr[i] && i <= end) i++;
        while(key < arr[j] && j >= start + 1) j--;
        if(i >= j) swap(&arr[j], &arr[start]);
        else swap(&arr[i], &arr[j]);
    }
    quick(arr, start, j-1);
    quick(arr, j+1, end);
}

int main(void) {
    int N;
    int tmp;
    int arr[1001] = {0, };
    int size = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        arr[size] = tmp;
        size++;
    }
    
    quick(arr, 0, size - 1);
    for(int i = 0; i < size; i++) {
        printf("%d\n", arr[i]);
    }
}

