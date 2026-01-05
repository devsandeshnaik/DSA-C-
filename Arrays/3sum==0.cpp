#include<iostream>
#include<vector>
#include<set>
using namespace std;

// https://leetcode.com/problems/3sum/description/
class Solution {
public:

    // Brute force approach works but runs out of time :: time complexity: n3
    vector<vector<int>> threeSumBrute(vector<int>& nums) {
        set<vector<int>> resultSet;
        vector<vector<int>> resultVector;
        for(int i=0; i<=nums.size()-1; i++) {
            for(int j=i+1; j<=nums.size()-1; j++) {
                for(int k=j+1; k<=nums.size()-1; k++) {
                    if((nums[i] + nums[j] + nums[k]) == 0) {
                        vector<int> vec = {nums[i], nums[j], nums[k]};
                        sort(vec.begin(), vec.end()); // sort vector to ensure set doesn not take in duplicates.
                        resultSet.insert(vec); // added to set to avoid duplicate records of resulting pair.
                    }
                }
            }
        }
        // turn set into vector
        for(vector<int> vec: resultSet) {
            resultVector.push_back(vec);
        }

        return resultVector;
    }

    // Optimsed version
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int> >result;
        sort(nums.begin(), nums.end());

        // looping until < n-2 since we need triplets , indexed from 0 : [n-3,n-2,n-1]
        for(int i = 0; i < nums.size()-2; i++) { 
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            // for each i we need to find a pair such that 
            // nums[i] + val1 + val2 == 0 => val1+val2 == -nums[i]
            // since pair is needed and array is sorted can use two pair method
            int left = i+1;
            int right = nums.size()-1;
            while(left < right) {
                int iVal = -1 * nums[i];
                int sum = nums[left] + nums[right];
                cout << "iVal " << iVal << "==" << "Sum " << sum << endl;
                if(iVal == sum) {
                    result.push_back( { nums[i], nums[left], nums[right]});
                    right--;
                    left++;
                    while(nums[left] == nums[left-1] && left < right) left++;
                    while(nums[right] == nums[right+1] && left < right) right--;
                    cout << "left: " << left << " right: " << right << " i: " << i <<endl;
                } else if (iVal > sum) {
                    left++;
                    while(nums[left] == nums[left-1] && left < right) left++;
                } else {
                    right--;
                    while(nums[right] == nums[right+1] && left > right) right--;
                }
            }
        }
        return result;
    }

    //From net does same as above but takes less time
    /*
        does not compute nums[i] + val1 + val2 == 0 => val1+val2 == -nums[i]
        rather use arr[i] + arr[left] + arr[k] since we know target is 0 dont need above computation
    */
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j<k){
                if(nums[j]+nums[i]+nums[k]<0) j++;
                else if(nums[i]+nums[j]+nums[k]>0) k--;
                else{
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }
        return ans;
    }
};


int main() {
    Solution sol;
    vector<int> vec = {-1,0,1,2,-1,-4};
    vector<vector<int>> result = sol.threeSum(vec);

    cout << "res size" << result.size() << endl;

    for(vector<int> vec: result) {
        cout << "pair: ";
        for(int item: vec) {
            cout << item << " -> ";
        }
        cout << endl;
    }
}