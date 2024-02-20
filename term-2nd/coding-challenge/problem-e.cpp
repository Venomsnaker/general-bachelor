#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int calculateUpperPosition(int n, int p, int k) {
    return (p + k) % n;
}

int calculateLowerPosition(int n, int p, int k) {
    int res = (p - k) % n;
    if (res < 0) {
        res += n;
    }
    return res;
}

void slimesManagement(int n, int m, int k, int t, vector<int> preSlimes) {
    vector<int> rooms(n);
    fill(rooms.begin(), rooms.end(), 0);
    
    for (auto pos: preSlimes) {
        rooms[pos] = 1;
    }

    for (int i = 1; i <= t; i++) {
        vector<int> curRooms(n);
        fill(curRooms.begin(), curRooms.end(), 0);

        for (int j = 0; j < rooms.size(); j++) {
            if (rooms[j] == 1) {
                int upper = calculateUpperPosition(n, j, k);
                int lower = calculateLowerPosition(n, j, k);
                curRooms[lower] = 1;
                curRooms[upper] = 1;
            }
        }
        for (int i = 0; i < curRooms.size(); i++) {
            rooms[i] = curRooms[i];
        }
    }
    
    for (auto val: rooms) cout << val << " ";
    cout << endl;
    cout << count(rooms.begin(), rooms.end(), 1);
}

int main() {
    vector<int> preSlimes = {1, 8};
    slimesManagement(12, 2, 1, 3, preSlimes);
    return 0;
}