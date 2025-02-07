#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(const string& s) {
    stack<char> stk;
    for (char ch : s) {
        if (ch == '(' || ch == '[' || ch == '{') {
            stk.push(ch);
        } else {
            if (stk.empty()) return false;
            char top = stk.top();
            if ((ch == ')' && top == '(') ||
                (ch == ']' && top == '[') ||
                (ch == '}' && top == '{')) {
                stk.pop();
            } else {
                return false;
            }
        }
    }
    return stk.empty();
}

int solution(string s) {
    int answer = 0;
    int len = s.length();
    
    for(int i = 0; i < len; i++){
        if(isValid(s)) answer++;
        
        s = s.substr(1) + s[0];
    }
    return answer;
}