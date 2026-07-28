#include<iostream>
#include<vector>

using namespace std;

//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/

vector<int> twoSum(vector<int>& numbers, int target) {
    int p1 = 0;
    int p2 = numbers.size()-1;

    while(p2 > p1) {
        int sum = numbers[p1] + numbers[p2];
        if(sum == target) {
            return {p1+1, p2+1};
        } else if( sum > target) {
            p2--;
        } else {
            p1++;
        }
    }

    return {};
}