/*
 *
 *  2019.12.21
 *  https://www.acmicpc.net/problem/1181
 *
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if(a.length() != b.length()) {
        return a.length() < b.length();
    } else {
        return a < b;
    }
}

int main(void) {
    string s;
    vector<string> v;
    int N = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        cin >> s;
        v.push_back(s);
    }
    
    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < v.size(); i++) {
        if(i == 0)
            cout << v[i] << '\n';
        else {
            if(v[i-1] != v[i]) {
                cout << v[i] << '\n';
            }
        }
    }
}
