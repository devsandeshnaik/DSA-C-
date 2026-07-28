#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    int sum = 0;
    int res = 0;
    map[0] = 1;

    for(int i: nums) {
        sum += i;
        int rem = sum%k;
        if(rem<0) { rem+=k; }
        if(map[rem] > 0) {
            res+=map[rem];
        }
        map[rem]+=1;
    }
    return res;
}

int main() {
    vector<int> vec = {4,5,0,-2,-3,1};
    int res = subarraysDivByK(vec, 5);
    cout << "RES: " << res << endl; 
}