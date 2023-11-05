#include <iostream>
#include <string.h>
using namespace std;

struct Student{
    char code[9];
    char name[39];
    char birthday [11];
    double score;

    Student() {};

    Student(const char* code, const char* name, const char* birthday, double score) {
        strcpy(this->code, code);
        strcpy(this->name, name);
        strcpy(this->birthday, birthday);
        this->score = score;
    }
};

struct Node {
    Student st;
    Node* next; 

    Node() {
        next = NULL;
    }
};

struct NodeList {
    Node* head;
    Node* tail;

    NodeList() {
        head = NULL;
        tail = NULL;
    }
};


class StudentDatabase {
public:
    NodeList* database;

    StudentDatabase() {
        database = new NodeList;
    }

    void addNewStudent() {
        Student st;
        inputStudent(st);
        Node* newNode = createNode(st);
        pushBack(newNode);
    }

    void addNewStudent(Student st) {
        Node* newNode = createNode(st);
        pushBack(newNode);
    }

    void inputStudent(Student &st) {
        cout << "Input code: ";
        cin.getline(st.code, 10);
        cout << "Input name: ";
        cin.getline(st.name, 39);
        cout << "Input birthday: ";
        cin.getline(st.birthday, 11);
        cout << "Input score: ";
        cin >> st.score;
        cin.ignore();
        return;
    }

    Node* createNode(Student st) {
        Node* newNode = new Node;
        if (newNode == NULL) return NULL;
        newNode->st = st;
        newNode->next = NULL;
        return newNode;
    }

    void pushBack(Node* newNode) {
        if (database->head == NULL) {
            database->head = newNode;
            database->tail = newNode;
        } else {
            database->tail->next = newNode;
            database->tail = newNode;
        }
        return;
    }

    void printStudents() {
        Node* cur = database->head;

        while (cur) {
            cout << cur->st.code << "---" << cur->st.name << "---" << cur->st.birthday << "---" << cur->st.score << endl;
            cur = cur->next;
        }
    }
};

int main() {
    StudentDatabase database;
    char code1[] = "1234";
    char name1[] = "huy";
    char birthday1[] = "17";
    double score1 = 9.5;
    Student st1 = Student(code1, name1, birthday1, score1);

    char code2[] = "5678";
    char name2[] = "han";
    char birthday2[] = "15";
    double score2 = 10;
    Student st2 = Student(code2, name2, birthday2, score2);


    database.addNewStudent(st1);
    database.addNewStudent(st2);
    database.printStudents();
    return 0;
}