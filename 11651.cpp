/*
 *
 *  2019.12.21
 *  https://www.acmicpc.net/problem/11651
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main(void) {
    vector<pair<int, int>>v;
    int N = 0;
    int x = 0;
    int y = 0;
    pair<int, int> p;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        p.first = x;
        p.second = y;
        v.push_back(p);
    }
    
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < N; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
}

