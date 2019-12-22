/*
 *
 *  2019.12.22
 *  https://www.acmicpc.net/problem/1003
 *
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int N = 0;
    int tmp = 0;
    int max = -1;
    vector<int> input;
    long long int zero[41] = {0, };
    long long int one[41] = {0, };
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        if(max < tmp) {
            max = tmp;
        }
        input.push_back(tmp);
    }
    zero[0] = 1;
    one[0] = 0;
    
    zero[1] = 0;
    one[1] = 1;
    
    for(int i = 2; i <= max; i++) {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }
    
    for(int i = 0; i < N; i++) {
        int index = input[i];
        printf("%lld %lld\n", zero[index], one[index]);
    }
}

