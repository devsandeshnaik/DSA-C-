#include<iostream>
#include<stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        string result;
        for(char ch: s) {
            if(!stk.empty() &&  stk.top() == ch) {
                result.erase(result.size()-1);
                stk.pop();
            } else {
                stk.push(ch);
                result.push_back(ch);
            }
        }
        return result;
    }
};


int main() {
    Solution sol = Solution();
    string str = "abbaca";
    string res = sol.removeDuplicates(str);
    cout << res << endl;
}