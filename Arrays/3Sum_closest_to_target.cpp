#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/3sum-closest/
class Solution {
public:
    int threeSumClosestBrute(vector<int>& nums, int target) {
        int lastDifference = INT_MAX;
        int resSum;
        for(int i = 0; i<= nums.size()-1; i++) {
            for(int j = i+1; j<= nums.size()-1; j++) {
                for(int k = j+1; k <= nums.size()-1; k++) {
                    int sum = nums[i] + nums[j] + nums[k];
                    if(sum == target) {
                        lastDifference = target;
                        resSum = sum;
                        return sum;
                    } 
                    cout << "Sum " << abs(target-sum) << "==" << lastDifference << endl;
                    if(abs(sum-target) < lastDifference &&  target != lastDifference ) {
                        lastDifference = abs(sum-target);
                        resSum = sum;
                    }
                }
            }
        }
        return resSum;
    }

    // Optimised with two sum
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int sum;
        for(int i=0; i <= nums.size()-2; i++) {
            if(diff == target) break;
            int left = i+1;
            int right = nums.size()-1;
            while (left < right)
            {
                int nSum = nums[i] + nums[left] + nums[right];
                if (nSum == target) { 
                    return nSum;
                } else if (nSum < target) {
                    int nDiff = abs(nSum - target);
                    if(nDiff < diff) {
                        diff = nDiff;
                        sum = nSum;
                    }
                    left++;
                    while(nums[left] == nums[left-1] && left < right) left++;
                } else {
                    int nDiff = abs(nSum - target);
                    if(nDiff < diff) {
                        diff = nDiff;
                        sum = nSum;
                    }
                    right--;
                    while(nums[right] == nums[right+1] && left < right) right--;
                }
            }
        }
        return sum;
    }

    // From net does not uses diff varible
    int threeSumClosestBest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        // Initialize closest sum with the first three elements
        int closestSum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int currentSum = nums[i] + nums[left] + nums[right];
                
                // Update closest sum if current is closer to target
                if (abs(currentSum - target) < abs(closestSum - target)) {
                    closestSum = currentSum;
                }
                
                if (currentSum < target) {
                    left++;
                } else if (currentSum > target) {
                    right--;
                } else {
                    // Exact match found
                    return currentSum;
                }
            }
        }
        
        return closestSum;
    }
};


int main() {
    vector<int> vec = {-1,2,1,-4};
    Solution sol;

    int result = sol.threeSumClosest(vec, 1);
    cout << "Closest sum: " << result << endl;
}