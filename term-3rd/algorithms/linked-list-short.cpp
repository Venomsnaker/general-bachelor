#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

struct LinkedList {
    Node* head;
    Node* tail;
};

void initLinkedList(LinkedList &l) {
    l.head = l.tail = NULL;
}

Node* createNode(int newData) {
    Node* n = new Node();
    n->data = newData;
    return n;
}

void addFront(LinkedList &l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        p->next = l.head;
        l.head = p;
    }
    return;
}

void traverse(LinkedList &l) {
    Node* cur = l.head;

    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
    return;
}


int main() {
    LinkedList l;
    initLinkedList(l);
    addFront(l, createNode(1));
    addFront(l, createNode(2));
    addFront(l, createNode(3));
    traverse(l);
    return 0;
}