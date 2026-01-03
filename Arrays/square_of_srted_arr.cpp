
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> negNum;
        vector<int> posNum;

        //splitting given array into two different array of +ve and -ve
        for(int i=0; i<=nums.size()-1; i++) {
            if(nums[i] >= 0) {
                posNum.push_back(nums[i]);
            } else {
                negNum.push_back(nums[i]);
            }
        }

        int posNumIndex = 0;
        int negNumIndex = negNum.size()-1;
        vector<int> resultArr;
        if(posNum.size() == 0) {
            // all are negetive numbers
            for(int i=negNum.size()-1; i>=0; i--) {
                resultArr.push_back(negNum[i] *  negNum[i]);
            }
            return resultArr;
        }

        if(negNum.size() == 0) {
            // all are positive numbers
            for(int i=0; i<=posNum.size()-1; i++) {
                resultArr.push_back(posNum[i] *  posNum[i]);
            }
            return resultArr;
        }

        cout << "pos arr size: " << posNum.size() << endl;
        cout << "neg arr size: " << negNum.size() << endl;

        // there are postive and negive numbers perform merging of array
        while(posNumIndex <= posNum.size()-1 || negNumIndex >= 0) {
            int posNumSq = posNum[posNumIndex] *  posNum[posNumIndex];
            int negNumSq = negNum[negNumIndex] *  negNum[negNumIndex];

            if(posNumSq < negNumSq) {
                resultArr.push_back(posNumSq);
                posNumIndex++;
            } else {
                resultArr.push_back(negNumSq);
                negNumIndex--;
            }

            cout << "pos index: " << posNumIndex << endl;
            cout << "neg index: " << negNumIndex << endl;

            if(posNumIndex > posNum.size()-1 && negNumIndex >= 0) {
                // No more postive numbers
                while(negNumIndex>=0) {
                    int negNumSq = negNum[negNumIndex] *  negNum[negNumIndex];
                    resultArr.push_back(negNumSq);
                    negNumIndex--;
                }
            }

            if(negNumIndex < 0 && posNumIndex <= posNum.size()-1) {
                // No more negetive numbers
                while(posNumIndex <= posNum.size()-1) {
                    int posNumSq = posNum[posNumIndex] *  posNum[posNumIndex];
                    resultArr.push_back(posNumSq);
                    posNumIndex++;
                }
            }
        }
        return resultArr;
    }

    vector<int> sortedSquares2(vector<int>& nums) {
        vector<int> resultArr(nums.size());
        int sIndex = 0;
        int eIndex = nums.size()-1;
        int rArrIndex = nums.size()-1;

        while(sIndex <= eIndex) {
            if((abs(nums[sIndex])) > (abs(nums[eIndex]))) {
                resultArr[rArrIndex] = nums[sIndex] * nums[sIndex];
                rArrIndex--;
                sIndex++;
            } else {
                resultArr[rArrIndex] = nums[eIndex] * nums[eIndex];
                rArrIndex--;
                eIndex--;
            }
        }
        return resultArr;
    }

    vector<int> sortedSquares3(vector<int>& nums) {
        vector<int> resultArr;
        resultArr.reserve(nums.size());

        int n = nums.size();

        // all negative
        if (nums[n-1] < 0) {
            for (int i = n-1; i >= 0; i--) {
                resultArr.push_back(nums[i] * nums[i]);
            }
            return resultArr;
        }

        // all positive
        if (nums[0] >= 0) {
            for (int i = 0; i < n; i++) {
                resultArr.push_back(nums[i] * nums[i]);
            }
            return resultArr;
        }

        // find first positive
        int pIndex = 0;
        while (nums[pIndex] < 0) pIndex++;
        int nIndex = pIndex - 1;

        // merge
        while (pIndex < n && nIndex >= 0) {
            int posSq = nums[pIndex] * nums[pIndex];
            int negSq = nums[nIndex] * nums[nIndex];

            if (posSq < negSq) {
                resultArr.push_back(posSq);
                pIndex++;
            } else {
                resultArr.push_back(negSq);
                nIndex--;
            }
        }

        // remaining negatives
        while (nIndex >= 0) {
            resultArr.push_back(nums[nIndex] * nums[nIndex]);
            nIndex--;
        }

        // remaining positives
        while (pIndex < n) {
            resultArr.push_back(nums[pIndex] * nums[pIndex]);
            pIndex++;
        }

        return resultArr;
    }
};


int main() {
    Solution sol;
    vector<int> vec = {-1,2,2};
    vector<int> vec1 = {0,3,10};
    vector<int> result = sol.sortedSquares3(vec);

    for(auto it = result.begin(); it < result.end(); it++) {
        cout << *it << endl;
    }
}