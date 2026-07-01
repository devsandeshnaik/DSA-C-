#include<iostream>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int minx = nums[0];
        int maxx = nums[0];
        int result = abs(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            int v1 = minx + nums[i];
            int v2 = maxx + nums[i];

            minx = min(v1, nums[i]);
            maxx = max(v2, nums[i]);

            result = max(result, max(abs(minx), abs(maxx)));
        }

        return result;
    }
};