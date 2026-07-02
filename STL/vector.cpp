#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main() {
    vector<int> vec1;
    vector<pair<int, string>> vec2;

    vec1.push_back(2);
    vector<int> ::  iterator it = vec1.begin();
    vec1.emplace(it, 4, 2);
}