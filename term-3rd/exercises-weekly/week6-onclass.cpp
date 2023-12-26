#include <iostream>
#include <list>
using namespace std;

static const int HASH_TABLE_SIZE = 13;

struct Hash {
    int hashTableSize;
    list<int> *table;
};

void createHash(Hash &h, int countSlots) {
    h.hashTableSize = countSlots;
    h.table = new list<int>[countSlots];
}

int hashFunc(Hash h, int x) {
    return (x % h.hashTableSize);
}

void insertItem(Hash &h, int key) {
    int idx = hashFunc(h, key);
    h.table[idx].push_back(key);
}

void deleteItem(Hash h, int key) {
    int idx = hashFunc(h, key);
    list<int>::iterator i;

    for (i = h.table[idx].begin(); i != h.table[idx].end(); i++) {
        if (*i == key) break;
    }

    if (i != h.table[idx].end()) h.table[idx].erase(i);
}

void displayHash(Hash h) {
    for (int i = 0; i < h.hashTableSize; i++) {
        cout << i;
        for (auto key: h.table[i]) cout << " -> " << key;
        cout << endl;
    }
}

int main() {
    Hash h;
    // Create a hash map with 13 slots
    createHash(h, HASH_TABLE_SIZE);
    cout << "Insert 1, 14, 5, 25 to the hash table" << endl;
    const int nums_size = 4;
    int nums[nums_size] = {1, 14, 5, 25}; 
    for (int i = 0; i < nums_size; i++) {
        insertItem(h, nums[i]);
    }
    displayHash(h);
    cout << endl;
    cout << "Delete 14 from the hash table" << endl;
    deleteItem(h, 14);
    displayHash(h);
    return 0;
}