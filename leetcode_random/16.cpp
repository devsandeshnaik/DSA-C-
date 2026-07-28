#include<iostream>
#include<vector>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int diff = INT_MAX;;
    int closestSum = 0;

    for(int i=0; i<=nums.size()-3; i++) {
        int p1 = i+1;
        int p2 = nums.size()-1;
        while(p2>p1) {
            int cSum = nums[i]+nums[p1]+nums[p2];
            if(cSum == target) {
                return cSum;
            } else  {
                int nDiff = abs(target-cSum);
                if(nDiff < diff) {
                    closestSum = cSum;
                    diff = nDiff;
                }
                if (cSum > target) { p2--; } else { p1++; }
            }
        }
    }

    return closestSum;
}