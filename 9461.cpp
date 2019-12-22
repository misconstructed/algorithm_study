/*
 *
 *  2019.12.22
 *  https://www.acmicpc.net/problem/9461
 *
*/

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    vector<int> v;
    long long int arr[101] = {0, };
    int N;
    int tmp;
    int max = -1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &tmp);
        v.push_back(tmp);
        if(max < tmp)
            max = tmp;
    }
    
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    for(int i = 3; i <= max; i++) {
        arr[i] = arr[i-2] + arr[i-3];
    }
    for(int i = 0; i < N; i++) {
        int index = v[i];
        printf("%lld\n", arr[index]);
    }
}

