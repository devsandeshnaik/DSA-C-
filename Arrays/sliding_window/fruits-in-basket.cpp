#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 0;
        int low = 0;
        map<int, int> dict;

        for(int high = 0; high < fruits.size(); high++) {
            res++;
            if(dict.find(fruits[high]) == dict.end()) {
                dict[fruits[high]] = 1;
            } else { 
                dict[fruits[high]]++;
            }

            if(dict.size() > 2) {
                dict[fruits[low]]--;
                if(dict[fruits[low]] == 0) dict.erase(fruits[low]);
                res--;
                low++;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<int> vec = {1,2,1};
    int maxFruits = sol.totalFruit(vec);
    cout << maxFruits << endl;

    vector<int> vec1 = {0,1,2,2};
    int maxFruits1 = sol.totalFruit(vec1);
    cout << maxFruits1 << endl;

    vector<int> vec2 = {1,2,3,2,2};
    int maxFruits2 = sol.totalFruit(vec2);
    cout << maxFruits2 << endl;
}