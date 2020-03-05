/*
 *
 *  2020.03.05
 *  https://www.acmicpc.net/problem/10808
 *
 */

#include <stdio.h>

int arr[30];

int main(void) {
    char a = 'a';
    char word[105];
    scanf("%s", word);
    int i = 0;
    
    while(word[i] != '\0') {
        char tmp = word[i];
        arr[tmp-a]++;
        i++;
    }
    
    for(int i = 0; i < 26; i++) {
        printf("%d ", arr[i]);
    }
}

