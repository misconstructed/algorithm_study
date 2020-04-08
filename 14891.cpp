/*
 *
 *  2020.04.08
 *  https://www.acmicpc.net/problem/14891
 *
*/

#include <stdio.h>

int arr[4][8];
int k;
int index;
int rotate;

int arr_count = 4;
int point_count = 8;

int n = 0;
int s = 1;

int clock = 1;
int nonclock = -1;

void rotate_func(int index, int dir) {
    int i = 0;
    if(dir == clock) {
        
        int last = arr[index][point_count - 1];
        for(i = point_count -1; i > 0; i--) {
            arr[index][i] = arr[index][i-1];
        }
        arr[index][0] = last;
    } else {
        int first = arr[index][0];
        for(i = 0; i < point_count - 1; i++) {
            arr[index][i] = arr[index][i+1];
        }
        arr[index][point_count-1] = first;
    }
}

int main(void) {
    int i = 0;
    int j = 0;
    for(i = 0; i < 4; i++) {
        for(j = 0; j < 8; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    
    scanf("%d", &k);
    for(i = 0; i < k; i++) {
        scanf("%d %d", &index, &rotate);
        
        int rotate_arr[4] = {0, 0, 0, 0};
        
        int current = index - 1;
        
        rotate_arr[current] = rotate;
        
        // left side
        for(j = current - 1; j >= 0; j--) {
            // 극이 다르면 반대 방향으로 회전
            if(arr[current][6] != arr[j][2]) {
                int new_dir = rotate * (-1);
                rotate_arr[j] = new_dir;
                    
                rotate = new_dir;
                current = j;
            } else {
                // 극이 같으면 더 이상 회전하지 않음, 이후 다른 톱니바퀴도 회전하지 않음
                break;
            }
        }
        
        current = index - 1;
        rotate = rotate_arr[current];
        // right side
        for(j = current+1; j < arr_count; j++) {
            // 극이 다르면 반대 방향으로 회전
            if(arr[current][2] != arr[j][6]) {
                int new_dir = rotate * (-1);
                rotate_arr[j] = new_dir;
                    
                rotate = new_dir;
                current = j;
            } else {
                // 극이 같으면 더 이상 회전하지 않음, 이후 다른 톱니바퀴도 회전하지 않음
                break;
            }
        }
        
        for(j = 0; j < arr_count; j++) {
            if(rotate_arr[j] != 0) {
                rotate_func(j, rotate_arr[j]);
            }
        }
    }
    
    int res = 0;
    res += arr[0][0];
    res += arr[1][0] * 2;
    res += arr[2][0] * 4;
    res += arr[3][0] * 8;
    
    printf("%d\n", res);
}

