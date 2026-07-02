#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        if (intervals.size() == 1) { return intervals; }
        sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a,const vector<int> &b) {
             return a[0] < b[0];
         });

        vector<vector<int>> result;
        vector<int> lastRange = intervals[0];
        for(int i = 1; i <= intervals.size()-1; i++) {
            vector<int> cRange = intervals[i];
            if(lastRange[1] >= cRange[0]) {
                lastRange = {lastRange[0],  max(lastRange[1], cRange[1])};
            } else {
                result.push_back(lastRange);
                lastRange = cRange;
            }
        }
        result.push_back(lastRange);
        return result;
    }

    vector<vector<int>> merge2(vector<vector<int>>& intervals) {

        if (intervals.size() == 1) { return intervals; }
        sort(intervals.begin(), intervals.end(),
         [](const vector<int> &a,const vector<int> &b) {
             return a[0] < b[0];
         });

        vector<vector<int>> result({intervals[0]});
        for(int i = 1; i <= intervals.size()-1; i++) {
            if(result.back()[1] >= intervals[i][0]) {
                result.back() = {result.back()[0],  max(result.back()[1], intervals[i][1])};
            } else {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
    
};

bool sortbyCond(const pair<int, int>& a,
                const pair<int, int>& b)
{
    if (a.first != b.first)
        return (a.first < b.first);
    else
       return (a.second > b.second);
}

int main() {
    Solution sol = Solution();
    vector<vector<int>> vec = {{1,3},{2,6},{8,10},{15,18}};

    vector<vector<int>> vece = {{1,4},{5,6}};
    //auto result = sol.merge(vec);

    vector<vector<int>> vecee = {{4,5},{1,4}, {0,4}};
    auto result = sol.merge2(vecee);

    
    // for(vector<int> it: result) {
    //     cout << "[" << it[0] << "," << it[1] << "]" << endl;
    // }


    for(int i = 1; i <= 10; i++) {
        cout << "i++" << i << endl;
    }
    cout << "====" << endl;
    for(int i = 1; i <= 10; ++i) {
        cout << "++i" << i << endl;
    }
}