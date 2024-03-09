#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

bool checkAnagram(string s1, string s2) {
    unordered_map<char, int> temp;

    for (auto s: s1) {
        temp[s]++;
    }
    for (auto s: s2) {
        temp[s]--;
    }
    for (auto it = temp.begin(); it != temp.end(); it++) {

        if (it->second != 0) return false; 
    }
    return true;
}


int main() {
    string a = "aha";
    string b = "oho";
    vector<int> res(4, 2);
    for (auto i: res) cout << i << endl;
    cout << checkAnagram(a, b) << endl;
}