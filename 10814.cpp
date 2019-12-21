/*
 *
 *  2019.12.21
 *  https://www.acmicpc.net/problem/10814
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, pair<int, string>> a,
             pair<int, pair<int, string>> b) {
    if(a.second.first != b.second.first) {
        return a.second.first < b.second.first;
    } else {
        return a.first < b.first;
    }
}

int main(void) {
    int N;
    int age;
    string name;
    vector<pair<int, pair<int, string>>> v;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        cin >> age >> name;
        pair<int, string> p;
        p.first = age;
        p.second = name;
        pair<int, pair<int, string>> in;
        in.first = i;
        in.second = p;
        v.push_back(in);
    }
    
    sort(v.begin(), v.end(), compare);
    
    for(int i = 0; i < v.size(); i++) {
        cout << v[i].second.first << ' ' << v[i].second.second << '\n';
    }
}

