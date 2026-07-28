#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
         vector<vector<int>> res;
        if(intervals.size() == 0) { return {newInterval}; }
        for(int i = 0; i <= intervals.size()-1; i++) {
            vector<int> vec = intervals[i];
            if(vec[1] >= newInterval[0] && vec[0] <= newInterval[1]) {
                cout << "IN IF" << endl;
                newInterval = {min(vec[0], newInterval[0]), max(newInterval[1], vec[1])};
                if(i+1 == intervals.size()) { res.push_back(newInterval); }
            } else {
                cout << "IN ELSE" << endl;
                if(newInterval[1]<vec[0]) {
                    res.push_back(newInterval);
                }
                res.push_back(vec);
            }
        }

        if(res.back()[1] < newInterval[0]) {
            res.push_back(newInterval);
        }

        return res;
}

int main() {
    vector<vector<int>> vec1 = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<vector<int>> vec2 = {{1,5}};
    vector<int> interval = {4,8};
    vector<int> interval2 = {2,3};
    vector<vector<int>> res = insert(vec2,interval2);
    for(vector<int> vecx: res) {
        for(int in: vecx) {
            cout << in << "=>" ;
        }
        cout << endl;
    }
}
