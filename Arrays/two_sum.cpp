#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<int> twoSumBrute(vector<int>& nums, int target) {
        for(int i = 0; i< nums.size(); i++) {
            for(int j = 1; j<= nums.size(); j++) {
                if(nums[i]+nums[j] == target) {
                    vector<int> res = {nums[i], nums[j]};
                    return res;
                }
            }
        }
        return vector<int>();
    }

    vector<int> twoSumUsingMap(vector<int>& nums, int target) {
        map<int, bool> numMap;
        for(int i = 0; i < nums.size(); i++) {
            int neededNumber = target - nums[i];
            if(numMap[neededNumber] == true) {
                vector<int> res = { neededNumber, nums[i],};
                return res;
            }
            numMap[nums[i]] = true;
        }
        return vector<int>();
    }

    /* 
        better approach but using maps takes lot of space
    */
    vector<int> twoSumIndicesUsingMap(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> numMap;
        for(int i = 0; i < nums.size(); i++) {
            int neededNumber = target - nums[i];
            if(numMap.find(neededNumber) != numMap.end()) {
                vector<int> res = { numMap[neededNumber], i,};
                return res;
            }
            numMap[nums[i]] = i;
        }
        return res;
    }

    /*
        - works only when the array is sorted
        - for unsorted array using maps is best option
        - can be used for values to given array is sorted
    */

    vector<int> twoSumIndicesUsing2Pointer(vector<int>& nums, int target) {
        int pointer1 = 0;
        int pointer2 = nums.size() - 1;
        while(pointer1 <= pointer2) {
            int sum =  nums[pointer1] + nums[pointer2];
            if(sum == target) {
                return {pointer1, pointer2};
            } else if (sum > target) {
                pointer2--;
            } else {
                pointer1++;
            }
        }
        return vector<int>();
    }
};



int main() {
    Solution sol;
    vector<int> vec = {2,7,1,15};
    vector<int> vecSorted = {1,2,7,15};
    
    vector<int> ans1 = sol.twoSumBrute( vec, 9);
    vector<int> ans2 = sol.twoSumUsingMap( vec, 9);
    vector<int> ans3 = sol.twoSumIndicesUsingMap( vec, 9);
    vector<int> ans4 = sol.twoSumIndicesUsing2Pointer( vecSorted, 9);

    
    // Brute force result
    cout << "twoSumBrute" << endl;
    for(auto it = ans1.begin(); it < ans1.end(); it++) {
        cout << *it << endl;
    }

    // Optimize result
    cout << "twoSumUsingMap" << endl;
    for(auto it = ans2.begin(); it < ans2.end(); it++) {
        cout << *it << endl;
    }

    // Optimize result for indices
    cout << "twoSumIndicesUsingMap" << endl;
    for(auto it = ans3.begin(); it < ans3.end(); it++) {
        cout << *it << endl;
    }

    // Optimize result for indices using pointers : constant space
    cout << "twoSumIndicesUsing2Pointer" << endl;
    for(auto it = ans4.begin(); it < ans4.end(); it++) {
        cout << *it << endl;
    }
}
