/*
 *
 *  2019.12.16
 *  https://www.acmicpc.net/problem/2751
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> v;
    int input;
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d", &input);
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++) {
        printf("%d\n", v[i]);
    }
}

