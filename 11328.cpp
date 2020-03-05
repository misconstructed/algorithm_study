/*
 *
 *  2020.03.05
 *  https://www.acmicpc.net/problem/11328
 *
 */

#include <stdio.h>

char a[1001];
char b[1001];

int res[1002];

int a_arr[30];
int b_arr[30];

int n;
char A = 'a';
int success;

int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 30; j++) {
            a_arr[j] = 0;
            b_arr[j] = 0;
        }
        scanf("%s %s", a, b);
        int j = 0;
        while(a[j] != '\0') {
            a_arr[a[j] - A]++;
            j++;
        }
        
        j = 0;
        while(b[j] != '\0') {
            b_arr[b[j] - A]++;
            j++;
        }
        
        success = 1;
        for(j = 0; j < 30; j++) {
            if(a_arr[j] != b_arr[j]) {
                success = 0;
                res[i] = 0;
                break;
            }
        }
        if(success == 1)
            res[i] = 1;
    }
    for(int i = 0; i < n; i++) {
        if(res[i] == 0) printf("Impossible\n");
        else printf("Possible\n");
    }
}

