#include <iostream>
#include <list>
#include <cstring>
using namespace std;

static const int DEFAULT_SIZE = 101;

template<class KeyType, class ItemType>
struct Node {
    KeyType key;
    ItemType item;
    Node<KeyType, ItemType>* nextPtr;
};

template<class KeyType, class ItemType>
struct Hash {
    int itemCount;
    int hashTableSize;
    Node<KeyType, ItemType> **hashTable;
};

template <class KeyType, class ItemType>
void initHash(Hash<KeyType, ItemType>& h) {
    h.itemCount = 0;
    h.hashTableSize = DEFAULT_SIZE;
    h.hashTable = new Node<KeyType, ItemType>*[DEFAULT_SIZE];
    for (int i = 0; i < DEFAULT_SIZE; i++) {
        h.hashTable[i] = nullptr;
    }
};

template <class KeyType, class ItemType>
int hashFunc(KeyType x, Hash<KeyType, ItemType> h) {
    int res = 0;
    for (auto ch: x) {
        res += int(ch - 'A');
    }
    return res % h.hashTableSize;
}

template <class KeyType, class ItemType>
void addItem(Hash<KeyType, ItemType> &h, const ItemType& newItem, const KeyType& searchKey) {
    Node<KeyType, ItemType>* newNode = new Node<KeyType, ItemType>;
    newNode->key = searchKey;
    newNode->item = newItem;
    newNode->nextPtr = nullptr;

    int hashIdx = hashFunc(searchKey, h);
    newNode->nextPtr = h.hashTable[hashIdx];
    h.hashTable[hashIdx] = newNode;
    h.itemCount++;
}

template <class KeyType, class ItemType>
void removeItem(Hash<KeyType, ItemType> &h, const KeyType& searchKey) {
    int hashIdx = hashFunc(searchKey, h);
    Node<KeyType, ItemType>* cur = h.hashTable[hashIdx];
    Node<KeyType, ItemType>* prev = nullptr;

    while (cur != nullptr && cur->key != searchKey) {
        prev = cur;
        cur = cur->nextPtr;
    }

    if (cur == nullptr) {
        cout << "The key you wish to delete is not in the list" << endl;
    }

    if (prev == nullptr) {
        // head;
        h.hashTable[hashIdx] = cur->nextPtr;
    } else {
        prev->nextPtr = cur->nextPtr;
    }
    delete cur;
    h.itemCount--;
}

template <class KeyType, class ItemType>
void displayDictionary(Hash<KeyType, ItemType> h) {
    for (int idx = 0; idx < h.hashTableSize; idx++) {
        Node<KeyType, ItemType>* cur = h.hashTable[idx];

        if (cur == nullptr) continue;

        while (cur != nullptr) {
            cout << cur->key << " - " << cur->item << " -> ";
            cur = cur->nextPtr;
        }
        cout << "null" << endl;
    }
}

int main() {
    Hash<string, string> h;
    initHash(h);
    addItem<string, string>(h, "A dangerous fish.", "Shark");
    addItem<string, string>(h, "A fish that lives in saltwater.", "Shark"); 
    addItem<string, string>(h, "A fruit that is yellow.", "Banana"); 
    addItem<string, string>(h, "Laugh out loud.", "Lol");
    displayDictionary<string, string>(h);
    cout << endl;
    cout << "Remove the first shark entry" << endl;
    removeItem<string, string>(h, "Shark");
    displayDictionary<string, string>(h);
    return 0;
}




