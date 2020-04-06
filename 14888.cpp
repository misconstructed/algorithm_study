/*
 *
 *  2020.04.07
 *  https://www.acmicpc.net/problem/14888
 *
*/

#include <stdio.h>
#include <stdlib.h>

int n;
int* input;
int* order;
// + : 1, - : 2, * : 3, / : 4
int op[4] = {0, 0, 0, 0};

long long int min = 1000000000;
long long int max = -1000000000;

void calc(int flag) {
    int i = 0;
    
    // if all operation is selected
    if(flag == (n-1)) {
        long long int compare;
        compare = input[0];
        for(i = 0; i < (n-1); i++) {
            if(order[i] == 1) {
                // +
                compare += input[i+1];
            } else if(order[i] == 2) {
                // -
                compare -= input[i+1];
            } else if(order[i] == 3) {
                // *
                compare *= input[i+1];
            } else if(order[i] == 4) {
                // /
                if(compare < 0) {
                    long long int tmp = compare * (-1);
                    tmp /= input[i+1];
                    compare = (-1) * tmp;
                } else {
                    compare /= input[i+1];
                }
            }
        }
        // compare min, max
        if(max < compare) {
            max = compare;
        }
        if(min > compare) {
            min = compare;
        }
    }
    
    for(i = 0; i < 4; i++) {
        // if there is an operation
        if(op[i] != 0) {
            // select
            op[i]--;
            order[flag] = i + 1;
            // move to next operation
            calc(flag + 1);
            // put the operation back
            order[flag] = 0;
            op[i]++;
        }
    }
}

int main(void) {
    int i = 0;
    
    scanf("%d", &n);
    // init input arr
    input = (int*)malloc(sizeof(int) * n);
    order = (int*)malloc(sizeof(int)* (n-1));
    
    for(i = 0; i < (n-1); i++) {
        order[i] = 0;
    }
    
    for(i = 0; i < n; i++) {
        scanf("%d", &input[i]);
    }
    
    for(i = 0; i < 4; i++) {
        scanf("%d", &op[i]);
    }
    
    calc(0);
    
    printf("%lld\n%lld\n", max, min);
}

