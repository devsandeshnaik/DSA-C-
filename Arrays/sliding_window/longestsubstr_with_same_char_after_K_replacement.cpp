#include<iostream>
#include<map>
using namespace std;

// https://leetcode.com/problems/longest-repeating-character-replacement/description/

/*
    You are given a string s and an integer k. You can choose any character of the string and change it to any
     other uppercase English character. You can perform this operation at most k times.
    Return the length of the longest substring containing the same letter you can get after performing the above operations.

    Example 1:
    Input: s = "ABAB", k = 2
    Output: 4
    Explanation: Replace the two 'A's with two 'B's or vice versa.

    Example 2:
    Input: s = "AABABBA", k = 1
    Output: 4
    Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
    The substring "BBBB" has the longest repeating letters, which is 4.
    There may exists other ways to achieve this answer too.
*/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int high = 0;
        int low = 0;
        int result = 0;
        map<char, int> dict;

        for(high = 0; high < s.length(); high++) {
            if(dict.find(s[high]) == dict.end()) {
                dict[s[high]] = 1;
            } else { dict[s[high]]++; }

            int length = (high-low)+1;
            int charWithMaxFreq = maxFreq(dict);
            int diff = length - charWithMaxFreq; 

            while(diff > k) {
                dict[s[low]]--;
                if(dict[s[low]] == 0) { dict.erase(s[low]); }
                low++;
                length = (high-low)+1;
                charWithMaxFreq = maxFreq(dict);
                diff = length - charWithMaxFreq; 
            }
            length = (high-low)+1;
            result = max(length, result);
        }
        return result;
    }

    int maxFreq(map<char, int> dict) {
        int max = 0;
        for( auto pair: dict) {
            if(pair.second > max) {
                max = pair.second;
            }
        }
        return max;
    }
};

int main() {
    Solution sol;
    string str = "ABAB";
    int longestSubStr = sol.characterReplacement( str, 2);
    cout << longestSubStr << endl;

    string str2 = "AABABBA";
    int longestSubStr2 = sol.characterReplacement( str2, 1);
    cout << longestSubStr2 << endl;
}