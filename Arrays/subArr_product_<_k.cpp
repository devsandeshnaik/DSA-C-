
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int currentUniqueNumIndex = 0;
        for(int i=currentUniqueNumIndex+1; i <= nums.size()-1; i++) {
            if(nums[i] != nums[currentUniqueNumIndex]) {
                currentUniqueNumIndex++;
                nums[currentUniqueNumIndex] = nums[i];
            }
        }
        currentUniqueNumIndex++;


        int prodCounts = 0;
        for(int i = 0; i <= nums.size()-1; i++) {
            int lastProd = 0;
            if(nums[i] < k) {
                prodCounts++;
                lastProd = nums[i];
                cout << "SLP: " << lastProd  << endl; 
            } else { continue; }
            for(int j=i+1; j <= nums.size()-1; j++) {
                if(lastProd * nums[j] >= k) {
                    continue;
                } else {
                    cout << "LP: " << lastProd << "==" << "j: " << nums[j] << endl; 
                    prodCounts++;
                    lastProd = lastProd * nums[j];
                }
            }
        }
        return prodCounts;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {10,5,2,6};
    vector<int> vec1 = {0,3,10};
    int result = sol.numSubarrayProductLessThanK(vec, 100);
    cout << "Product Counts: " << result << endl;
}