/*
 *
 *  2019.12.18
 *  https://www.acmicpc.net/problem/11650
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) {
        return a.first < b.first;
    } else {
        return a.second < b.second;
    }
}

int main(void) {
    int N;
    int x, y;
    vector<pair<int, int>> v;
    pair<int, int> tmp;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d %d", &x, &y);
        tmp.first = x;
        tmp.second = y;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < N; i++) {
        printf("%d %d\n", v[i].first, v[i].second);
    }
    
}

