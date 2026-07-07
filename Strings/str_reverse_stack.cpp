#include<iostream>
#include<stack>

using namespace std;

int main() {
    string str = "Hellow World";
    stack<char> stk;
    for(char ch: str) {
        stk.push(ch);
    }
    string res;
    while (!stk.empty())
    {
        res.push_back(stk.top());
        stk.pop();
    }

    cout << res << endl;
    
}