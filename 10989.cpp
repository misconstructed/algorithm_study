/*
 *
 *  2019.12.16
 *  https://www.acmicpc.net/problem/10989
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 *  기존의 정렬 방식으로 문제를 풀면 메모리 초과
 *  수가 10,000 보다 작거나 같은 자연수라는 점을 이용해서
 *  O(n) 의 복잡도로 문제 풀이
 */

int main(void) {
    int arr[10001] = {0, };
    int N;
    int input;
    int i, j;
    scanf("%d", &N);
    
    for(i = 0; i < N; i++) {
        scanf("%d", &input);
        arr[input]++;
    }
    
    for(i = 0; i < 10001; i++) {
        if(arr[i] != 0) {
            for(j = 0; j < arr[i]; j++) {
                printf("%d\n", i);
            }
        }
    }
}

