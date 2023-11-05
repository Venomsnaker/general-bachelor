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

    void deleteNode(Node* &head, int pos) {
        Node* temp;
        Node* prev;
        temp = head; prev = head;

        for (int i = 0; i < pos; i++) {
            if (i == 0 && pos == 1) {
                head = head->next;
                delete(temp);
            }
            else {
                if (i == pos - 1 && temp) {
                    prev->next = temp->next;
                    delete(temp);
                } else {
                    prev = temp;

                    if (prev == NULL) break;
                    temp = temp->next;
                }
            }
        }
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