#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        sort(arr, arr+n);
        int pairs = 0;    
        for(int i=0; i <= n-2; i++) {
            int left = i+1;
            int right = n-1;
            while( left < right) {
                int tempSum = arr[i] + arr[left] + arr[right];
                if(tempSum >= sum) {
                    right --; 
                } else {
                    pairs = pairs + (right - left);
                    left++;
                }
            }
        }
        return pairs;
    }
    
};



int main() {
    long long vec[] = {5, 1, 3, 4, 7};
    Solution sol;

    long long triplets = sol.countTriplets(5, 12, vec);
    cout << "Triplet count less than sum:  " << triplets << endl;
}