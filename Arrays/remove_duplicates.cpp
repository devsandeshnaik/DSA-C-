#include<iostream>
#include<vector>
using namespace std;

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }

        int currentUniqueNumIndex = 0;
        for(int i=currentUniqueNumIndex+1; i <= nums.size()-1; i++) {
            if(nums[i] != nums[currentUniqueNumIndex]) {
                currentUniqueNumIndex++;
                nums[currentUniqueNumIndex] = nums[i];
            }
        }
        return currentUniqueNumIndex+1;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1,1,2,3,4,5,5,5,6,7,7,9};
    sol.removeDuplicates(vec);


    for(auto it = vec.begin(); it < vec.end(); it++) {
        cout << *it << endl;
    }
}