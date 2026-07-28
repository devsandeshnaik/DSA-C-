#include<iostream>
#include<vector>

using namespace std;

int maxActiveSectionsAfterTrade(string s) {
    int size = s.size();
    int ones = count(begin(s), end(s), '1');

    vector<int> vec;
    int index = 0;
    while (index < size) {
        if(s[index] == '0') {
            int start = index;
            while( index < size && s[index] == '0')index++;
            vec.push_back(index-start);
        } else {
            index++;
        }
    }

    int pairsum = 0;
    for(int i = 1; i < vec.size(); i++) {
        int newSum = vec[i] + vec[i-1];
        if(newSum > pairsum)
            pairsum = newSum;
    }

    return pairsum+ones;
}

int main() {
    string s = "01";
    int res = maxActiveSectionsAfterTrade(s);
    cout << "RES: " << res << endl;
}