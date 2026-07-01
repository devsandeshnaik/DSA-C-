#include<iostream>
#include<vector>

using namespace std;

class Solution {
    public:

    // works but too slow.
    int pivotIndexBrute(vector<int> &arr) {
        for(int i = 0; i<= arr.size()-1; i++) {
            if(i==0 && sum(arr, i+1, arr.size()-1) == 0) {
                return 0;
            }
            if(sum(arr, 0, i-1) == sum(arr, i+1, arr.size()-1)) {
                return i;
            }

            if(i==arr.size()-1 && sum(arr, 0, i-1) == 0) {
                return arr.size()-1;
            }
        }
        return -1;
    }

    int sum(vector<int> &vec, int i1, int i2) {
        int sum = 0;
        if(i1 == i2) { return 0; }
        for(int i = i1; i <= i2; i++) {
            sum += vec[i];
        }
        return sum;
    }

    // Using prefix
int pivotIndex(vector<int> &nums) {
    vector<int> pre(nums.size(),0);
    vector<int> suf(nums.size(),0);

    for(int i = 1; i <= nums.size()-1; i++ ) {
        pre[i] = pre[i-1] + nums[i-1];
    }

      for(int i = nums.size()-2; i >= 0; i-- ) {
        suf[i] = suf[i+1] + nums[i+1];
        if (suf[i] == pre[i]) {
            return i;
        }
    }
    return - 1;
}

// better memory
 int pivotIndexMen(vector<int> &nums) {
    int sum = 0;
    int pfix = 0;

    for(int i = 0; i <= nums.size()-1; i++ ) {
        sum += nums[i];
    }

    cout << "===" << sum << endl;

    for(int i = 0; i <= nums.size()-1; i++ ) {
        int sfix = sum - pfix - nums[i];
        if(pfix == sfix) { return i; }
        pfix += nums[i];
    }
    return - 1;
    }

};



int main() {
    Solution obj = Solution();
    vector<int> vec = {1,7,3,6,5,6};
    int pivot = obj.pivotIndexMen(vec);
    cout << pivot << "====" <<endl;
}