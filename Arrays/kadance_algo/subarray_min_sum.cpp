#include<iostream>

using namespace std;

int minSubArray(vector<int>& nums) {
    int bestSum = nums[0];
    int result = nums[0];

    for(int i = 0; i < nums.size(); i++) {
        bestSum = bestSum + nums[i];
        if(nums[i] < bestSum) {
            bestSum = nums[i];
        }
        if(bestSum < result) {
            result = bestSum;
        }
        return result;
    }
        
}