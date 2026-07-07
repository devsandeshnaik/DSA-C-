#include<iostream>
#include<vector>
#include<unordered_set>
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

    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int res = 0;
        unordered_set<int> map; 
        for(int n :  nums) {
            sum += n;
            if(sum < k) {
                map.insert(sum);
            } else if(sum == k) {
                res++;
                map.insert(sum);
            } else {
                int diff = sum-k;
                if(map.find(diff) != map.end()) {
                    res++;
                }
                map.insert(sum);
            }
        }
        return res;
    }
};

int main() {
    Solution sol = Solution();
    vector<int> vec = {100,1,2,3,4};
    vector<int> vec1 = {1,2,3};

    int res1 = sol.subarraySum(vec, 3);
   // int res2 = sol.subarraySumBrute(vec1, 3);

    cout << res1 << "==="  << endl;
}