#include<iostream>
#include<vector>

using namespace std;

class PrefixAndSuffix {
public:

vector<int> prefix(vector<int> &arr) {
    vector<int> prefix(arr.size(),0);
    for(int i = 1; i<= arr.size()-1; i++) {
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    return prefix;
}

vector<int> suffix(vector<int> &arr) {
    vector<int> suffix(arr.size(), 0);
    for(int i = arr.size()-2; i>=0; i--) {
        suffix[i] = suffix[i+1]+ arr[i+1];
    }
    return suffix;
}

};

int main() {

    PrefixAndSuffix obj = PrefixAndSuffix();
    vector<int> vec = {1,2,8,9,3};
    vector<int> prefixRes = obj.prefix(vec);
    vector<int> suffixRes = obj.suffix(vec);

    for(auto it = prefixRes.begin(); it < prefixRes.end(); it++) {
        cout << *it << endl;
    }

    cout << "===================" << endl;

    for(auto it = suffixRes.begin(); it < suffixRes.end(); it++) {
        cout << *it << endl;
    }
}