#include<iostream>
#include<vector>
using namespace std;


//https://www.geeksforgeeks.org/problems/segregate-0s-and-1s5106/1

class Solution {
  public:
    
    // Brute force: Works but exceeds time limit
    void segregate0and1(vector<int> &arr) {
        for(int i=0; i < arr.size()-1; i++) {
            if(arr[i] == 1) {
                int ptr = i+1;
                while(arr[ptr]!=0 && ptr < arr.size()-1) {
                    ptr++;
                }
                if(arr[ptr] == 0) {
                    swapAt(arr, i, ptr);
                }
            }
        }
    }

    void swapAt(vector<int> &arr, int index1, int index2) {
        int temp = arr[index1];
        arr[index1] = arr[index2];
        arr[index2] = temp;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {0,0,1,1,0};
    sol.segregate0and1(vec);


    for(auto it = vec.begin(); it < vec.end(); it++) {
        cout << *it << endl;
    }
}