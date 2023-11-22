#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;

    Node() {
        data = 0;
        next = NULL;
        prev = NULL;
    }

    Node(int data) {
        next = NULL;
        prev = NULL;
        this->data = data;
    }
};

class DoublyLinkedList{
public:
    Node* head;

    Node* createNode(int data) {
        Node* new_node = new Node(data);
        return new_node;
    }

    void printLinkedList() {
        Node* cur = head;
        if (!cur) return;

        while(cur) {
            cout << cur->data << " "; 
            cur = cur->next;
        }
        cout << endl;
    }

    void pushFront(Node* &cur, Node* node) {
        if(!cur) {
            cur = node;
        }
        else {
            node->next = cur;
            cur->prev = node;
            cur = node;
        }
        return;
    }

    void pushBack(Node* &cur, Node* node) {
        if (!cur) {
            cur = node;
        }
        else {
            Node* temp = cur;
        
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = node;
            node->prev = temp;
        }
        return;
    }

    void pushPrevious(int data, Node* new_node) {
        if (!head) return;
        Node* cur = head;

        while (cur && cur->data != data) cur = cur->next;
        if (!cur) return;

        Node* cur_prev = cur->prev;
        cur_prev->next = new_node;
        new_node->prev = cur_prev;
        new_node->next = cur;
        cur->prev = new_node;
        return;
    }

    void deleteNode(int data) {
        Node* cur = head;
        
        while (cur && cur->data != data) cur = cur->next;
        if(!cur) return;

        Node* cur_prev = cur->prev;
        Node* cur_next = cur->next;
        cur_prev->next = cur_next;
        if (cur_next) cur_next->prev = cur_prev;
        delete(cur);
    }
};


int main() {
    DoublyLinkedList dll;
    dll.head = NULL;
    dll.pushBack(dll.head, dll.createNode(1));
    dll.pushBack(dll.head, dll.createNode(2));
    dll.pushBack(dll.head, dll.createNode(3));
    dll.pushFront(dll.head, dll.createNode(4));
    dll.pushPrevious(2, dll.createNode(5));
    dll.deleteNode(1);
    dll.printLinkedList();
}