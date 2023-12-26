#include <iostream>
#include <list>
using namespace std;

// Should be a prime number
static const int DEFAULT_SIZE = 11;

template <class KeyType, class ItemType>
struct Node {
    KeyType key;
    ItemType item;
    Node<KeyType, ItemType>* nextNode;
};

template <class KeyType, class ItemType>
struct HashTable {
    int itemsSize;
    int hashTableSize;
    Node<KeyType, ItemType> **hashTable;
};

template <class KeyType, class ItemType>
void initHashTable(HashTable<KeyType, ItemType> &h) {
    h.itemsSize = 0;
    h.hashTableSize = DEFAULT_SIZE;
    h.hashTable = new Node<KeyType, ItemType>*[DEFAULT_SIZE];

    for (int i = 0; i < DEFAULT_SIZE; i++) {
        h.hashTable[i] = nullptr;
    }
}

template <class KeyType, class ItemType>
int hashFunc(KeyType x, HashTable<KeyType, ItemType> h) {
    // ASsume Keytype == String
    int res = 0;
    for (auto ch: x) {
        res += int(ch - 'A');
    }
    return res % h.hashTableSize;
}

template <class KeyType, class ItemType>
void insertItem(HashTable<KeyType, ItemType> &h, const KeyType &searchKey, const ItemType &newItem) {
    Node<KeyType, ItemType> *newNode = new Node<KeyType, ItemType>;
    newNode->key = searchKey;
    newNode->item = newItem;
    newNode->nextNode = nullptr;

    int idx = hashFunc(searchKey, h);
    newNode->nextNode = h.hashTable[idx];
    h.hashTable[idx] = newNode;
    h.itemsSize++;
}

template <class KeyType, class ItemType>
void removeItem(HashTable<KeyType, ItemType> &h, const KeyType &searchKey) {
    int hashIdx = hashFunc(searchKey, h);
    Node<KeyType, ItemType> *curr = h.hashTable[hashIdx];
    Node<KeyType, ItemType> *prev = nullptr;

    while (curr != nullptr && curr->key != searchKey) {
        prev = curr;
        curr = curr->nextNode;
    }

    if (curr == nullptr) {
        cout << "The item you wish to delete is not in the hash table." << endl;
        return;
    }

    if (prev == nullptr) {
        h.hashTable[hashIdx] = curr->nextNode;
    } else {
        prev->nextNode = curr->nextNode;
    }
    delete curr;
    h.itemsSize--;
}

template <class KeyType, class ItemType>
void displayHashTable(HashTable<KeyType, ItemType> h) {
    for (int idx = 0; idx < h.hashTableSize; idx++) {
        Node<KeyType, ItemType> *curr = h.hashTable[idx];

        if (curr == nullptr) continue;

        while (curr != nullptr) {
            cout << curr->key << "-" << curr->item << " -> ";
            curr = curr->nextNode;
        }
        cout << "nullptr" << endl;
    }
}

int main() {
    HashTable<string, int> h;
    initHashTable(h);

    insertItem<string, int>(h, "Shark", 1);
    insertItem<string, int>(h, "Banana", 2);
    insertItem<string, int>(h, "Shark", 3);
    insertItem<string, int>(h, "Apple", 4);

    displayHashTable<string, int>(h);
    cout << endl;;
    return 0;
}

