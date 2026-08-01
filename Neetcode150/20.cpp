#include<iostream>
#include<stack>

using namespace std;
bool isValid(string s) {
        stack<char> stck;

    for(char c: s) {
        if(c == '{' || c == '[' || c == '(') {
            stck.push(c);
        } else {
            if(stck.empty()) return false;
            if(c == '}' && stck.top() == '{') {
                stck.pop();
            } else if(c == ']' && stck.top() == '[') {
                stck.pop();
            } else if(c == ')' && stck.top() == '(') {
                stck.pop();
            } else { return false; }
        }
    }
    bool res = stck.empty() ? true : false;
    return res;
 }