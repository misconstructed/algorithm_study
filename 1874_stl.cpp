/*
 *
 *  2020.03.11
 *  https://www.acmicpc.net/problem/10828
 *
 */

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> s;
vector<char> res;
queue<int> q;

int tmp;
int n;
int main(void) {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &tmp);
        q.push(tmp);
    }
    for(int i = 1; i <= n; i++) {
        s.push(i);
        res.push_back('+');
        while(!s.empty() && s.top() == q.front()) {
            q.pop();
            s.pop();
            res.push_back('-');
        }
    }
    if(!s.empty()) {
        printf("NO\n");
    } else {
        for(int i = 0; i < res.size(); i++) {
            printf("%c\n", res[i]);
        }
    }
}


