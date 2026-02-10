#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/minimum-size-subarray-sum/description/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int low = 0;
        int high = 0;
        int res = INT_MAX;
        int sum = 0;

        while(high < nums.size()) {
            sum += nums[high];
            while(sum >= target) {
                int newLenght =  (high-low) + 1;
                res = min(res, newLenght);
                sum = sum - nums[low];
                low++;
            }
            
            high++;
        }
        return (res == INT_MAX) ? 0 : res;
    }

    // From net: same techniques, bit different coding way.
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minlen=INT_MAX,left=0;
        long long sum=0;
        for(int right=0;right<n;++right){
            sum+=nums[right];
            while(sum>=target){
                minlen=min(right-left+1,minlen);
                sum-=nums[left];
                left++;
            }
        }
        return minlen==INT_MAX?0:minlen;
    }
};



int main() {
    Solution sol;
    vector<int> vec = {2,3,1,2,4,3};
    int minSize = sol.minSubArrayLen( 7, vec);
    cout << minSize << endl;
}