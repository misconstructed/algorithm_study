/*
 *
 *  2020.03.17
 *  https://www.acmicpc.net/problem/2493
 *
 */

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int n;
stack<pair<int, int>> s;
vector<int> res;
int input;

int main(void) {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &input);
        pair<int, int> p = make_pair(input, i);
        
        while(!s.empty() && s.top().first < input) {
            s.pop();
        }
        if(s.empty()) {
            printf("0 ");
            s.push(p);
        } else {
            printf("%d ", s.top().second);
            s.push(p);
        }
    }
    
}

