/*
 *
 *  2019.12.29
 *  https://www.acmicpc.net/problem/1463
 *
*/

#include <iostream>
#include <vector>

using namespace std;

long long int getmin(long long int a, long long int b) {
    if(a == -1) {
        return b;
    } else if(b == -1) {
        return a;
    } else if(a > b) {
        return b;
    } else {
        return a;
    }
}

int main(void) {
    long long int n = 0;
    vector<long long int> v;
    scanf("%lld", &n);
    v.push_back(0);
    v.push_back(0);
    for(int i = 2; i <= n; i++) {
        long long int three = -1;
        long long int two = -1;
        long long int one = -1;
        if(i % 3 == 0) {
            three = v[i/3] + 1;
        }
        if(i % 2 == 0) {
            two = v[i/2] + 1;
        }
        one = v[i-1] + 1;
        long long int min = getmin(getmin(three, two), one);
        v.push_back(min);
    }
    printf("%lld\n", v[n]);
}

