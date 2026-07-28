#include<iostream>
#include<vector>

using namespace std;

int numSubarrayProductLessThanK(vector<int>& nums, int k) {
    int productCounts=0;
    int start = 0;
    int product = 1;
    for(int end = 0; end <= nums.size()-1; end++) {
        product = product*nums[end];
        if(product<k) { productCounts += end-start+1; }
        while (product >= k) {
            product = product/nums[start];
            start++;
            if(product<k) { productCounts += end-start+1; }
        }
    }
    return productCounts;
}

int main() {
    vector<int> vec = {10,5,2,6};
    vector<int> vec2 = {686, 28, 455, 675, 605, 29, 942, 48, 502, 889, 854, 206, 231, 796, 272, 565, 887, 969, 558, 13, 22, 455, 145, 804, 15};
    int count = numSubarrayProductLessThanK(vec, 100);
    //int count2 = numSubarrayProductLessThanK(vec2, 515854);
    cout <<"Counts: " << count << endl;
}