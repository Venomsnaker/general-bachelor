#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    
    Node() {
        data = 0;
        next = NULL;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
    Node *head;

public:
    LinkedList() {head = NULL;}

    void insertNode(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteNode(int pos) {
        
    }

    void printList() {
        Node* temp = head;

        if (head == NULL) {
            cout << "List empty" << endl;
            return;
        }

        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};

int main() {

}