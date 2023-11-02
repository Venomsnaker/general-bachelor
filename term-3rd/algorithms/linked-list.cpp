#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;

    node(int new_data) {
        data = new_data;
    }
};

void push(node *head, int data) {
    node *new_node = new node(data);
    new_node->next = head;
    head = new_node;
}

int main() {
    cout << "Hello Hell!" << endl;
    return 0;
}