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

    Node* CreateNode(int data) {
        Node* new_node = new Node(data);
        return new_node;
    }

    void PrintLinkedList() {
        Node* cur = head;
        if (!cur) return;

        while(cur) {
            cout << cur->data << " "; 
            cur = cur->next;
        }
        cout << endl;
    }

    void PushFront(Node* &cur, Node* node) {
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

    void PushBack(Node* &cur, Node* node) {
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

    void PushPrevious(int data, Node* new_node) {
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

    void DeleteNode(int data) {
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
    dll.PushBack(dll.head, dll.CreateNode(3));
    dll.PushBack(dll.head, dll.CreateNode(5));
    dll.PushBack(dll.head, dll.CreateNode(4));
    dll.PushFront(dll.head, dll.CreateNode(2));
    dll.PushPrevious(5, dll.CreateNode(1));
    dll.DeleteNode(1);
    dll.PrintLinkedList();
}