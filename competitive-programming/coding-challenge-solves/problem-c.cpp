#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void findPaths(int cur, int k, int n, int maxHeight, vector<int>& path, int curN) {
    if (n == 0) {
        if (cur == k && curN == 0) {
            cout << 0 << " ";
            for (int i: path) cout << i << " ";
            cout << endl;
        }
    return;
    }

    if (cur + 1 <= maxHeight) {
        path.push_back(cur + 1);
        findPaths(cur + 1, k, n - 1, maxHeight, path, curN - (cur + 1));
        path.pop_back();
    }

    if (cur - 1 >= 0) {
        path.push_back(cur - 1);
        findPaths(cur - 1, k, n - 1, maxHeight, path, curN - (cur - 1));
        path.pop_back();
    }
}

int main() {
    vector<int> path;
    unordered_map<string, vector<vector<int>>> memo;
    findPaths(0, 1, 7, 5, path, 10);
    return 0;
}