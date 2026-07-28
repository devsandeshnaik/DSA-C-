#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

bool isHappy(int n) {
    unordered_set<int> set;
    while(n != 1) {
        long int result = 0;
        while(n != 0) {
            int remainder = n%10;
            n = n/10;
            result += remainder*remainder;
            cout << "Remainder = " << remainder <<  " n = " << n <<  " result = " << result << endl;  
        }
        if(set.find(result) != set.end()) { break; }
        set.insert(result);
        n = result;
    }
    if(n == 1) {
        return true;
    }
    return false;
}

int main() {
   bool res = isHappy(2);
   cout  << "RESULT: " << res << endl;
}