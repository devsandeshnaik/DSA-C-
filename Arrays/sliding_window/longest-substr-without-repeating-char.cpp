#include<iostream>
#include<map>
using namespace std;

//https://leetcode.com/problems/longest-substring-without-repeating-characters/
//sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low =0;
        int res = 0;
        map<char, int> map;

        for(int high = 0; high < s.size(); high++) {
           char c = s[high];
           while(map.find(c) != map.end()) {
                map.erase(s[low]);
                low++;
           }
           map[c] = 1;
           res = max(res, high - low + 1);
        }
        return res;
    }
};

int main() {
    Solution sol;
    string str = "abcabcbb";
    int maxSubSeq = sol.lengthOfLongestSubstring( str);
    cout << maxSubSeq << endl;
    string str1 = "aaaa";
    int maxSubSeq1 = sol.lengthOfLongestSubstring( str1);
    cout << maxSubSeq1 << endl;
    string str2 = "pwwkew";
    int maxSubSeq2 = sol.lengthOfLongestSubstring( str2);
    cout << maxSubSeq2 << endl;
}