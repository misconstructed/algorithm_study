/*
 *
 *  2019.12.18
 *  https://www.acmicpc.net/problem/1427
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main(void) {
    long long int input = 0;
    int mod;
    vector<int> v;
    scanf("%lld", &input);
    while(input != 0) {
        mod = input % 10;
        v.push_back(mod);
        input = input / 10;
    }
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++) {
        printf("%d", v[i]);
    }
}



