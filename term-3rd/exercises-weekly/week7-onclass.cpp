#include <iostream>
using namespace std;

struct Element {
    int key;
    int priority;
};

struct Node {
    Element data;
    Node *pNext;
};

struct PriorityQueue {
    Node *pFront;
};

void initPriorityQueue(PriorityQueue &q) {
    q.pFront = NULL;
}

Node* createNode(int key, int priority) {
    Node* newNode = new Node;
    newNode->data.key = key;
    newNode->data.priority = priority;
    newNode->pNext = NULL;
    return newNode;
}

void enqueue(PriorityQueue &q, Node* newNode) {
    if (q.pFront == NULL) q.pFront = newNode;
    else {
        Node* cur = q.pFront;
        Node* prev = NULL;

        while (cur != NULL && cur->data.priority > newNode->data.priority) {
            prev = cur;
            cur = cur->pNext;
        }

        if (prev == nullptr) {
            newNode->pNext = q.pFront;
            q.pFront = newNode;
        } else {
            newNode->pNext = cur;
            prev->pNext = newNode;
        }
    }
    return;
}

Node* dequeue(PriorityQueue &q) {
    if (q.pFront == NULL) return NULL;
    else {
        Node* cur = q.pFront;
        q.pFront = cur->pNext;
        return(cur);
    }
}

void display_queue(PriorityQueue &q) {
    if (q.pFront == NULL) return;
    else {
        Node* cur = q.pFront;

        while (cur != NULL) {
            cout << cur->data.key << ": " << cur->data.priority << endl;
            cur = cur->pNext;
        }
    }
}

int main() {
    PriorityQueue q;
    initPriorityQueue(q);
    enqueue(q, createNode(111, 1));
    enqueue(q, createNode(11, 1));
    enqueue(q, createNode(33, 3));
    enqueue(q, createNode(22, 2));
    enqueue(q, createNode(222, 2));
    display_queue(q);
    cout << endl;
    cout << "Dequeue: " << endl;
    Node* dequeueNode = dequeue(q);
    cout << dequeueNode->data.key << ": " << dequeueNode->data.priority << endl;
    cout << endl;
    display_queue(q);
    return 0;
}