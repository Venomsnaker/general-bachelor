#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

struct List {
    Node* head;
    Node* tail;
};

void initLinkedList(List& l) {
    l.head = l.tail = NULL;
}

void updateListTail(List &l) {
    Node* temp = l.head;

    if (temp == NULL) {
        l.head = NULL;
        l.tail = NULL;
        return;
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    l.tail = temp;
}

Node* createNode(int data) {
    Node* new_node = new Node(data);
    return new_node;
}

void addFirst(List& l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        p->next = l.head;
        l.head = p;
    }
}

void addLast(List& l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
}

void insertBeforeTarget(List& l, Node* p, Node* target) {
    if (l.head == NULL) return;

    if (l.head->data == target->data) {
        addFirst(l, p);
        return;
    }

    Node* temp = l.head;
    
    while (temp->next != NULL && temp->next->data != target->data) temp = temp->next;

    if (temp->next == NULL) cout << "The node you wish to insert after: " << temp->data << " is not in the list." << endl;
    else {
        p->next = temp->next;
        temp->next = p;
    }
    return;
}

int getListLength(List& l) {
    Node* temp = l.head;
    int len = 0;

    while (temp != NULL) {
        len += 1;
        temp = temp->next;
    }
    return len;
}

void insertMidList(List& l, Node* p) {
    int len = getListLength(l);
    Node* temp = l.head;

    for (int _ = 0; _ < len / 2 - 1; _++) {
        temp = temp->next;
    }

    if (temp != NULL) {
        p->next = temp->next;
        temp->next = p;
    }
    else {
        l.head = l.tail = p;
    }
    return;
}

void pushList(int arr[], int len, List& l) {
    for (int i = 0; i < len; i++) {
        addLast(l, createNode(arr[i]));
    }
    return;
}

bool searchNode(List &l, int key) {
    Node* temp = l.head;

    while (temp) {
        if (temp->data == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void removeEntry(List& l, int key) {
    if (l.head == NULL) return;

    Node* dummy = createNode(0);
    dummy->next = l.head;
    Node* curr = l.head;
    Node* prev = dummy;

    while (curr != NULL) {
        if (curr->data == key) {
            while(curr != NULL && curr->data == key) {
                curr = curr->next;
            }
            prev->next = curr;
            if (curr == NULL) break;
        }
        else {
            prev = curr;
        }
        curr = curr->next;
    }
    l.head = dummy->next;
    updateListTail(l);
    return;
}

void outputList(List l) {
    Node* temp = l.head;

    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void visualizeLinkedList() {
    List l;
    const int len = 5;
    int nums[len] = {2, 4, 6, 8, 10};
    cout << "Initialize then add last 2, 4, 6, 8, 10 to the list." << endl;
    initLinkedList(l);
    pushList(nums, len, l); 
    outputList(l);
    cout << endl;

    cout << "At 3 to the middle of the list." << endl;
    insertMidList(l, createNode(3));
    outputList(l);
    cout << endl;

    cout << "At 1 before 4 in the list.." << endl;
    insertBeforeTarget(l, createNode(1), createNode(4));
    outputList(l);
    cout << endl;

    cout << "Delete 6 from the list." << endl;
    removeEntry(l, 6);
    outputList(l);
}

int main()
{
    visualizeLinkedList();
}

