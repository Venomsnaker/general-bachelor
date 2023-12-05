#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int P = 13;

struct HashTable {
    vector<pair<int, int>> h[P];

    public:
        void insert(string name) {
            int nameSum = 0;

            for (int i = 0; i < name.size(); i++) {
                nameSum += (int)(name[i] - 'A');
            }
            int key = nameSum % P;


            int hkey = getHash(key);

            for (auto p: h[hkey]) {
                if (p.first == key) return;
            }
            h[hkey].emplace_back(key, nameSum);
        }

        int find(int key) {
            int hkey = getHash(key);
            for (auto p: h[hkey]) {
                if (p.first == key) return p.second;
            }
            return 0;
        }
    
    private:
        int getHash(int key) {
            return key % P;
        }
};

int main() {
    
    return 0;
}