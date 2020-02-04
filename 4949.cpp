/*
 *
 *  2020.02.03
 *  https://www.acmicpc.net/problem/4949
 *  getline(cin, s[count]);
 *
*/

#include <iostream>
#include <stack>
#include <vector>

using namespace std;



int main(void) {
    string s[10001];
    
    vector<int> v;
    int count = 0;
    
    while(true) {
        getline(cin, s[count]);
        if(s[count][0] == '.') break;
        
        stack<char> one;
        bool tmp = true;
        for(int i = 0; i < s[count].length(); i++) {
            if(s[count][i] == '(') {
                one.push('(');
            } else if(s[count][i] == ')') {
                if(one.empty() == true) {
                    v.push_back(0);
                    tmp = false;
                    printf("no\n");
                    break;
                } else {
                    char c = one.top();
                    one.pop();
                    if(c != '(') {
                        v.push_back(0);
                        tmp = false;
                        printf("no\n");
                        break;
                    }
                }
            } else if(s[count][i] == '[') {
                one.push('[');
            } else if(s[count][i] == ']') {
                if(one.empty() == true) {
                    v.push_back(0);
                    tmp = false;
                    printf("no\n");
                    break;
                } else {
                    char c = one.top();
                    one.pop();
                    if(c != '[') {
                        v.push_back(0);
                        tmp = false;
                        printf("no\n");
                        break;
                    }
                }
            }
        }
        if(tmp == true) {
            if(one.empty()==true) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
        
        count++;
    }
}

