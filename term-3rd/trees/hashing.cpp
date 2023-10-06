#include <vector>
using namespace std;

const int P = 1e6 + 3;

struct HashTable {
    vector< pair<int,int> > h[P];

public:
    void insert(int key, int value) {
        int hkey = getHash(key);\

        for (auto p : h[hkey]) {
            if (p.first == key) {
                return;
            }
        }
        h[hkey].emplace_back(key, value);
    }

    int find(int key) {
        int hkey = getHash(key);

        for(auto p : h[hkey]) {
            if (p.first == key) {
                return p.second;
            }
        }
        return 0;
    }

private:
    int getHash(int key) {
        return key % P;
    }
};

