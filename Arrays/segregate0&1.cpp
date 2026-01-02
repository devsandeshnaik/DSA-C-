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

    // Using two pointers both starting from 0th index
    void segregate0and1Pointer(vector<int> &arr) {
        int pointer1Index = 0;
        int pointer2Index = 1;
        while(pointer2Index != arr.size()) { // when pointer 2 is at last index marks ends of array
            while(arr[pointer1Index] != 1 && pointer1Index < arr.size()) {
                if(pointer2Index == pointer1Index) {
                    pointer2Index++;
                }
                pointer1Index++;
            }
            while(arr[pointer2Index] != 0 && pointer2Index < arr.size()) {
                pointer2Index++;
            }
            if (pointer2Index != arr.size()) {
                swapAt(arr, pointer1Index, pointer2Index);
                pointer2Index++;
            }
        }
    }

    // Using two pointers one starting from 0th index and other for last index. FASTER
    void segregate0and1Pointer2(vector<int> &arr) {
        int startIndex = 0;
        int endIndex = arr.size()-1;
        while(startIndex < endIndex) { // when pointer 2 is at last index marks ends of array
           while(arr[startIndex] != 1 && startIndex < endIndex) {
            startIndex++;
           }
        
           while(arr[endIndex] != 0 && endIndex > startIndex) {
            endIndex--;
           }

           swapAt(arr, startIndex, endIndex);
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
    sol.segregate0and1Pointer2(vec);


    for(auto it = vec.begin(); it < vec.end(); it++) {
        cout << *it << endl;
    }
}