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
 *  ������ ���� ������� ������ Ǯ�� �޸� �ʰ�
 *  ���� 10,000 ���� �۰ų� ���� �ڿ������ ���� �̿��ؼ�
 *  O(n) �� ���⵵�� ���� Ǯ��
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

