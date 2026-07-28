#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

//https://leetcode.com/problems/subarray-sum-equals-k/
class Solution {
public:

    //Brute force
    int subarraySumBrute(vector<int>& nums, int k) {
        int result = 0;
        for(int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for(int j = i; j <nums.size(); j++) {
                sum += nums[j];
                if(sum == k) {
                    result += 1;
                }
            }
        }
        return result;
    }

    //Optimised verion using prefix and cummulative sum method
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_map<int, int> map; 
        map[0]=1;
        for(int n :  nums) {
            sum += n;
            int diff = sum-k;
            if(map.find(diff) != map.end()) {
                res += map[diff];
            }
            map[sum] += 1;
            cout << n << map[2] << endl;
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> vec = {100,1,2,3,4};
    vector<int> vec1 = {1,1,1};

    int res1 = sol.subarraySum(vec1, 2 );
   // int res2 = sol.subarraySumBrute(vec1, 2);

    cout << res1  << endl;

    unordered_map<int, int> map; 
    map[0]=1;
    cout << map[2] << endl;
}