#include<iostream>

using namespace std;


int maximumSum(vector<int>& arr) {
    int nDelete = arr[0];
    int oDelete = INT_MIN;
    int result = arr[0];

    for(int i = 0; i < arr.size(); i++) {
        int prevNDelete = nDelete;
        int prevODelete = oDelete;

        nDelete = max(nDelete+arr[i], arr[i]);

        if(prevODelete == INT_MIN) {
            prevODelete = arr[i];
        }

        oDelete = max(prevODelete+arr[i], prevNDelete);

        result = max(result, max(nDelete, oDelete));
    }

    return result;

}