#include<iostream>
#include<vector>
using namespace std;

// https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1
// Sliding window with fixed window size
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int low = 0;
        int high = k - 1;
        int sum = 0;
        int res = 0;
        for(int i = low; i <= high; i++) {
            sum += arr[i];
        }

        while(high <= arr.size()-1) { //while(high < arr.size())
            res = max(sum, res);
            //cout << "res => " << res << endl;
            low++;
            high++;
            //if(high == arr.size()+1) { break;}
            sum = (sum-arr[low-1])+arr[high];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1, 4, 2, 10, 23, 3, 1, 0, 20};
    int maxSum = sol.maxSubarraySum(vec, 4);
    cout << maxSum << endl;
}