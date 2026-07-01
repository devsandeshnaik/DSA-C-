#include<iostream>
#include<map>
using namespace std;

// https://www.geeksforgeeks.org/problems/longest-k-unique-characters-substring0853/1
class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        map<char, int> dict;
        int start = 0;
        int result = 0;

        for(int end = 0; end < s.size()-1; end++) {
            if(dict.find(s[end]) != dict.end()) {
                dict[end] = dict[end] + 1;
            } else {
                dict[end] = 1;
            }

            while(dict.size() > k) {
                if(dict[start] > 1) {
                    dict[start]--;
                } else {
                    dict[start].
                }
            }
        }
    }
};

int main() {
    Solution sol;
    string str = "aabacbebebe";
    int maxSubSeq = sol.longestKSubstr( str, 3);
    cout << maxSubSeq << endl;
    string str1 = "aaaa";
    int maxSubSeq1 = sol.longestKSubstr( str1, 2);
    cout << maxSubSeq1 << endl;
    string str2 = "mlg";
    int maxSubSeq2 = sol.longestKSubstr( str2, 1);
    cout << maxSubSeq2 << endl;
}