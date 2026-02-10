#include<iostream>
#include<map>
using namespace std;


class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        map<char,int> dict;
        int low = 0;
        int result = 0;

        for(int high = 0; high < s.size(); high++) {
            char c = s[high];
            if(dict.find(c) == dict.end()) {
                dict.insert({c, 1});
            } else {
                dict[c] = dict[c] + 1;
            }
            
            while(dict.size() > k) {
                
                dict[s[low]] = dict[s[low]] - 1;
                if(dict[s[low]] == 0) dict.erase(s[low]);
                low++;
            }
            if(dict.size() == k) {
                result = max(result, (high-low)+1);
            }
        }
        return (result == 0) ? -1 : result;
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