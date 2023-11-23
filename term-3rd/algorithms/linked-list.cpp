#include <iostream>
#include <cstring>
using namespace std;

struct Node {
    int id;
    char data[32];

    Node* next;

    Node(int id, const char* data) {
        this->id = id;
        strcpy(this->data, data);
        next = NULL;
    }
};

struct LinkedList {
    Node* head;
    Node* tail;
};

void initLinkedList(LinkedList &l) {
    l.head = l.tail = NULL;
}

void mergeSortedLinkedList(LinkedList list1, LinkedList list2, LinkedList &res) {
    Node* l1 = list1.head;
    Node* l2 = list2.head;

    if (l1->data > l2->data) {
        res.head = l1;
        l1 = l1->next;
    } else {
        res.head = l2;
        l2 = l2->next;
    }

    Node* temp = res.head;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data > l2->data) {
            temp->next = l1;
            l1 = l1->next;
        } else {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if (l1 != NULL) {
        temp->next = l1;
    } else {
        temp->next = l2;
    }
}

Node* createNode(int id, const char* data) {
    Node* new_node = new Node(id, data);
    return new_node;
}

int getLinkedListLength(LinkedList l) {
    Node* temp = l.head;
    int len = 0;

    while (temp != NULL) {
        len += 1;
        temp = temp->next;
    }
    return len;
}

void updateListTail(LinkedList &l) {
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

void addFront(LinkedList &l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        p->next = l.head;
        l.head = p;
    }
    return;
}

void addBack(LinkedList &l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
    return;
}

void insertById(LinkedList &l, Node* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        if (p->id < l.head->id) {
            addFront(l, p);
            return;
        }

        if (p->id > l.tail->id) {
            addBack(l, p);
            return;
        }

        Node* temp = l.head;

        while (temp->next != NULL && p->id > temp->next->id) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
        return;
    }
}

void insertBeforeTarget(LinkedList &l, Node* p, int id) {
    if (l.head == NULL) return;

    if (l.head->id == id) {
        addFront(l, p);
        return;
    }

    Node* temp = l.head;
    
    while (temp->next != NULL && temp->next->id != id) temp = temp->next;

    if (temp->next == NULL) cout << "The node you wish to insert after: "<< id << " is not in the list." << endl;
    else {
        p->next = temp->next;
        temp->next = p;
    }
    return;
}

void insertAfterTarget(LinkedList &l, Node* p, int id) {
    if (l.head == NULL) return;

    Node* temp = l.head;

    while (temp != NULL && temp->id != id) temp = temp->next;

    if (temp == NULL) cout << "The node you wish to insert after: "<< id << " is not in the list." << endl;
    else {
        if (temp == l.tail) {
            addBack(l, p);
        }
        else {
            p->next = temp->next;
            temp->next = p;
        }
    }
    return;
}

void insertNFromStart(LinkedList &l, Node* p, int pos) {
    int len = getLinkedListLength(l);
    if (pos <= 0) {
        addFront(l, p);
        return;
    }
    if (pos >= len){
        addBack(l, p);
        return;
    } 

    Node* prev = createNode(0, "");
    prev->next = l.head;

    for (int i = 0; i < pos; i++) {
        prev = prev->next;
    } 
    p->next = prev->next;
    prev->next = p;
    return;
}

void insertNFromEnd(LinkedList &l, Node* p, int pos) {
    Node *slow = l.head, *fast = l.head;
    int len = getLinkedListLength(l);

    if (pos <= 0) {
        addBack(l, p);
        return;
    }
    if (pos >= len){
        addFront(l, p);
        return;
    } 
    
    for (int i = 0; i < pos; i++) {
        fast = fast->next;
    }

    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    p->next = slow->next;
    slow->next = p;
    return;
}

void deleteNodesById(LinkedList &l, int id) {
    if (l.head == NULL) return;

    Node* dummy = createNode(0, "");
    dummy->next = l.head;
    Node* curr = l.head;
    Node* prev = dummy;

    while (curr != NULL) {
        if (curr->id == id) {
            while(curr != NULL && curr->id == id) {
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

void deleteDuplicatedNodes(LinkedList &l) {
    if (l.head == NULL || l.head->next == NULL) return;

    Node* dummy = createNode(0, "");
    dummy->next = l.head;
    Node* curr = l.head;
    Node* prev = dummy;

    while (curr != NULL){
        if (curr->next != NULL && curr->id == curr->next->id){
            while (curr->next != NULL && curr->id == curr->next->id){
                curr = curr->next;
            }
            prev->next = curr->next;
        }
        else{
            prev = curr;
        }
        curr = curr->next;
    }
    l.head = dummy->next;
    updateListTail(l);
    return;
}

void makeLinkedListUnique(LinkedList &l) {
    if (l.head == NULL || l.head->next == NULL) return;

    Node* dummy = createNode(0, "");
    dummy->next = l.head;
    Node* curr = l.head;
    Node* prev = dummy;

    while (curr != NULL){
        if (curr->next != NULL && curr->id == curr->next->id){
            while (curr->next != NULL && curr->id == curr->next->id){
                curr = curr->next;
            }
            prev->next = curr;
        }
        else{
            prev = curr;
        }
        curr = curr->next;
    }
    l.head = dummy->next;
    updateListTail(l);
    return;
}

void reverseLinkedList(LinkedList &l) {
    Node* prev = NULL;
    Node* curr = l.head;

    while (curr != NULL) {
        Node* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    l.head = prev;
    updateListTail(l);
    return;
}

bool searchNode(LinkedList &l, int key) {
    Node* temp = l.head;

    while (temp) {
        if (temp->id == key) return true;
        temp = temp->next;
    }
    return false;
}

void printLinkedList(LinkedList l) {
    Node* temp = l.head;

    while (temp != NULL) {
        cout << temp->id << " " << temp->data << " " << endl;
        temp = temp->next;
    }
    return;
}

int main() {
    LinkedList l;
    initLinkedList(l);
    insertById(l, createNode(1, "Alice"));
    insertById(l, createNode(3, "Cleopatra"));
    insertById(l, createNode(4, "Electron"));
    insertById(l, createNode(2, "Bard"));
    insertById(l, createNode(5, "France"));
    deleteNodesById(l, 1);
    //reverseLinkedList(l);
    // insertBeforeTarget(l, createNode(6, "Good"), 3);
    // insertBeforeTarget(l, createNode(7, "Hans"), 1);
    // insertAfterTarget(l, createNode(8, "Ian"), 4);
    // insertAfterTarget(l, createNode(9, "June"), 5);
    //deleteDuplicatedNodes(l);
    cout << (l.head->data) << endl;
    cout << (l.tail->data) << endl;
    printLinkedList(l);
    return 0;
}