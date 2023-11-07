#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Task 1
struct Node {
    int key;
    Node* left, * right;

    Node(int val) {
        this->key = val;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    Node* createNode(int key) {
        Node* newNode = new Node(key);
        return newNode;
    }

    void insertNode(Node* &node, int val) {
        if (node == NULL) {
            node = createNode(val);
            return;
        }

        if (node->key > val) {
            insertNode(node->left, val);
        }
        else {
            // node->key <= val
            insertNode(node->right, val);
        }
    }

    Node* deleteNode(Node* node, int val) {
        if (node == NULL) {
            return NULL;
        }

        if (node->key > val) {
            node->left = deleteNode(node->left, val);
        } 
        else if (node->key < val) {
            node->right = deleteNode(node->right, val);
        }
        else {
            if (node->left == NULL) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (node->right == NULL) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            else {
                Node* parent = node;
                Node* succ = node->right;

                while (succ->left != NULL) {
                    parent = succ;
                    succ = succ->left;
                }

                if (parent != node) {
                    parent->left = succ->right;
                }
                else {
                    parent->right = succ->right;
                }

                node->key = succ->key;
                delete succ;
            }
        }
        return node;
    }

    int getTreeHeight(Node* cur) {
        if (cur == NULL) return 0;
        return max(1 + getTreeHeight(cur->left), 1 + getTreeHeight(cur->right));
    }

    int getNodeSumLargerThanX(int x) {
        int sum = 0;
        modifyTraverseForSum(root, sum, x);
        return sum;
    }

    bool searchRecursively(Node* node, int val) {
        if (node == NULL) return 0;
        if (node->key == val) return 1;

        if (node->key > val) {
            return searchRecursively(node->left, val);
        }
        else {
            // node->key < val
            return searchRecursively(node->right, val);
        }
    }

    bool searchIteratively(Node* node, int val) {
        while (node) {
            if (node->key == val) return 1;

            if (node->key > val) node = node->left;
            else node = node->right;
        }
        return 0;
    }

    void traversePreorder(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        traversePreorder(node->left);
        traversePreorder(node->right);
    }

    void traverseInorder(Node* node) {
        if (!node) return;
        traverseInorder(node->left);
        cout << node->key << " ";
        traverseInorder(node->right);
    }

    void traversePostorder(Node* node) {
        if (!node) return;
        traversePostorder(node->left);
        traversePostorder(node->right);
        cout << node->key << " ";
    }

    void traverseByLevel() {
        int n_temp;
        queue<Node*> temp;
        temp.push(root);

        while (temp.size() != 0) {
            n_temp = temp.size();

            for (int i = 0; i < n_temp; i++) {
                Node* cur = temp.front();
                temp.pop();

                if (cur) {
                    cout << cur->key << " ";
                    if (cur->left) temp.push(cur->left);
                    if (cur->right) temp.push(cur->right);
                }
            }
            cout << endl;
        }
    }

private:
    void modifyTraverseForSum(Node* node, int &sum, int x) {
        if (!node) return;
        modifyTraverseForSum(node->left, sum, x);
        if (root->key > x) sum += root->key; 
        modifyTraverseForSum(node->right, sum, x);
    }
};

void demonstrateBST() {
    // Initialize
    BST tree;
    tree.root = tree.createNode(5);
    tree.insertNode(tree.root, 9);
    tree.insertNode(tree.root, 3);
    tree.insertNode(tree.root, 2);
    tree.insertNode(tree.root, 6);
    tree.insertNode(tree.root, 4);
    tree.insertNode(tree.root, 11);

    cout << "Task 1" << endl;

    // Functions
    cout << "Create a BST with level order traversal (l->r):" << endl;
    tree.traverseByLevel();

    cout << "Preorder Traversal:" << endl;
    tree.traversePreorder(tree.root);
    cout << endl;

    cout << "Inorder Traversal:" << endl;
    tree.traverseInorder(tree.root);
    cout << endl;

    cout << "Postorder Traversal:" << endl;
    tree.traversePostorder(tree.root);
    cout << endl;

    cout << "Tree heigh: " << tree.getTreeHeight(tree.root) << endl;
    cout << "Sum of nodes > 3 = " << tree.getNodeSumLargerThanX(3) << endl;
    cout << "Exist node 4 in the tree (iterative): " << tree.searchIteratively(tree.root, 4) << endl;
    cout << "Exist node 1 in the tree (recursive): " << tree.searchRecursively(tree.root, 1) << endl;
    cout << "Delete node 1 then print the tree (level order)" << endl;
    tree.deleteNode(tree.root, 11);
    tree.traverseByLevel();
}

// Task 2
struct Birthday {
    int year;
    int month;
    int date;

    Birthday() {};

    Birthday(int newYear, int newMonth, int newDate) {
        year = newYear;
        month = newMonth;
        date = newDate;
    }
};

struct Customer {
public:
    string phoneNumber;
    string name;
    string address;
    Birthday birthday;
    Customer *left, *right;

    Customer() : left(NULL), right(NULL) {};

    Customer(string phoneNumber, string name, string address, Birthday birthday) {
        this->phoneNumber = phoneNumber;
        this->name = name;
        this->address = address;
        this->birthday = birthday;
        left = NULL;
        right = NULL;
    }
};

bool compareBirthday(Birthday d1, Birthday d2) {
    if (d1.year > d2.year) return true;
    if (d1.year < d2.year) return false;

    if (d1.month > d2.month) return true;
    if (d1.month < d2.month) return false;

    if (d1.date > d2.date) return true;
    return false;
}

bool checkSameBirthday(Birthday d1, Birthday d2) {
    if (d1.year == d2.year && d1.month == d2.month && d1.date == d2.date) return true;
    return false;
}

class BST_Customer {
public:
    Customer* root;

    Customer* createCustomer(string phoneNumber, string name, string address, Birthday birthday) {
        Customer* new_customer = new Customer(phoneNumber, name, address, birthday);
        return new_customer;
    }

    void insertCustomer(Customer* &customer, string phoneNumber, string name, string address, Birthday new_birthday) {
        if (customer == NULL) {
            customer = createCustomer(phoneNumber, name, address, new_birthday);
            return;
        }

        if (compareBirthday(customer->birthday, new_birthday)) {
            insertCustomer(customer->left, phoneNumber, name, address, new_birthday);
        }
        else {
            insertCustomer(customer->right, phoneNumber, name, address, new_birthday);
        }
    }

    void printDatabase(Customer* cus) {
        if (!cus) return;
        printDatabase(cus->left);
        cout << cus->name << "---" << cus->phoneNumber << "---" << cus->address << "---" << cus->birthday.year << "/" << cus->birthday.month << "/" << cus->birthday.date << endl;
        printDatabase(cus->right);
    }
    
    void getSameBirthdayCustomer(Customer* customer, Birthday target) {
        if (!customer) return;
        if (checkSameBirthday(customer->birthday, target)) {
            cout << customer->name << "---" << customer->phoneNumber << "---" << customer->address << "---" << customer->birthday.year << "/" << customer->birthday.month << "/" << customer->birthday.date << endl;
        }
        getSameBirthdayCustomer(customer->left, target);
        getSameBirthdayCustomer(customer->right, target);
    }

    void deleteTree(Customer* customer) {
    if (customer == NULL) return;
    deleteTree(customer->left);
    deleteTree(customer->right);
    delete customer;
}

    ~BST_Customer() {
        deleteTree(root);
    }
};

void demonstrateCustomerDatabase() {
    cout << "Task 2" << endl;
    BST_Customer customer_database;
    customer_database.root = NULL;
    // Initialize
    cout << "Print the pre-initialize BST (insert in order A,C,D,B,E) - inorder traversal:" << endl;
    customer_database.insertCustomer(customer_database.root, "0999", "A", "Viet Nam", Birthday(1960, 5, 15));
    customer_database.insertCustomer(customer_database.root, "0222", "C", "Greek", Birthday(2000, 3, 24));
    customer_database.insertCustomer(customer_database.root, "0555", "D", "Oman", Birthday(2004, 4, 17));
    customer_database.insertCustomer(customer_database.root, "0111", "B", "Australia", Birthday(1980, 2, 15));
    customer_database.insertCustomer(customer_database.root, "0333", "E", "France", Birthday(1960,5,15));
    customer_database.printDatabase(customer_database.root);
    cout << "Find those who birthdate is 15/05/1960: " << endl;
    Birthday target = Birthday(1960,5,15);
    customer_database.getSameBirthdayCustomer(customer_database.root, target);
}

int main()
{
    demonstrateBST();
    demonstrateCustomerDatabase();
    return 0;
}
