#include <iostream>
#include<vector>
using namespace std;

struct Node {
    int key;
    Node *next;
        
    Node(int keyNew) {
        this->key = keyNew;
        next = NULL;
    }
};

struct LinkedList {
    Node *head;
    Node *tail;
};

void initLinkedList(LinkedList &l) {
    l.head = l.tail = NULL;
}

Node* createNode(int key) {
    Node* nodeNew = new Node(key);
    return nodeNew;
}

void addFront(LinkedList& l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        p->next = l.head;
        l.head = p;
    }
    return;
}

void addBack(LinkedList& l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
    return;
}

void insertNodeWhileSorted(LinkedList &l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        if (p->key < l.head->key) {
            addFront(l, p);
            return;
        }

        if (p->key > l.tail->key) {
            addBack(l, p);
            return;
        }

        Node* temp = l.head;

        while (temp->next != NULL && p->key > temp->next->key) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
        return;
    }
}

vector<int> getNodePositions(LinkedList l, int x) {
    if (l.head == NULL) return {-1};

    vector<int> res;
    Node* temp = l.head;
    int curPos = 1;
    bool flag = false;

    while (temp != NULL) {
        if (temp->key == x) {
            if (!flag) flag = true;
            res.push_back(curPos);
        }

        curPos++;
        temp = temp->next;
    }

    if (flag == true) return res;
    else return { -1 };
}

void printLinkedList(LinkedList l) {
    cout << "In ra danh sach lien ket: " << endl;
    Node* temp = l.head;
    cout << "Head: " << l.head->key;
    cout << " Tail: " << l.tail->key << endl;
    cout << "Cac gia tri trong danh sach lien ket la: ";

    while (temp != NULL) {
        cout << temp->key << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void visualizeLinkedList() {
    LinkedList l1;
    initLinkedList(l1);
    cout << "Thiet lap linked list voi cac gia tri lan luot la: 1, 5, 3, 3, 7, 5." << endl;
    const int n1 = 6;
    int nodeList1[n1] = {1, 5, 3, 3, 7, 5};

    for (int i = 0; i < n1; i++) {
        addBack(l1, createNode(nodeList1[i]));
    }

    printLinkedList(l1);
    int x1 = 4;
    vector<int> res = getNodePositions(l1, x1);
    cout << "Cac vi tri cua " << x1 << " la: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;

    int x2 = 5;
    res = getNodePositions(l1, x2);
    cout << "Cac vi tri cua " << x2 << " la: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << endl;

    LinkedList l2;
    initLinkedList(l2);
    cout << "Lan luot them 3, 2, 8, 4, 6 vao mot danh sach lien ket moi." << endl;
    const int n2 = 5;
    int nodeList2[n2] = { 3, 2, 8, 4, 6 };

    for (int i = 0; i < n2; i++) {
        insertNodeWhileSorted(l2, createNode(nodeList2[i]));
    }
    printLinkedList(l2);
    return;
}

int main()
{
    visualizeLinkedList();
}


