#include<iostream>

using namespace std;

int maxSubArrayProd(vector<int>& nums) {
    int minEnding = nums[0];
    int maxEnding = nums[0];
    int result = nums[0];

    for(int i = 1; i < nums.size(); i++) {
        int v1 = minEnding * nums[i];
        int v2 = maxEnding * nums[i];

        minEnding = min(min(v1,v2), nums[i]);
        maxEnding = max(max(v1,v2), nums[i]);

        result = max(result, max(minEnding, maxEnding));
        
    }
    return result;
}