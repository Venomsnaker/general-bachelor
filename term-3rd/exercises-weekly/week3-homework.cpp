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

    void addNewStudentByCode(Student st) {
        Node* newNode = createNode(st);
        pushByCode(newNode);
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

    void pushByCode(Node* newNode) {
        if (database->head == NULL || strcmp(database->head->st.code, newNode->st.code) >= 0) {
            newNode->next = database->head;
            database->head = newNode;
        } else {
            Node* current = database->head;
            while (current->next != NULL && strcmp(current->next->st.code, newNode->st.code) < 0) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    void printStudents() {
        Node* cur = database->head;

        while (cur) {
            cout << cur->st.code << " - " << cur->st.name << " - " << cur->st.birthday << " - " << cur->st.score << endl;
            cur = cur->next;
        }
    }

    void printStudentByCode(char* codeTarget) {
        Node* cur = database->head;

        while (cur) {
            if (strcmp(codeTarget, cur->st.code) == 0)
            cout << cur->st.code << " - " << cur->st.name << " - " << cur->st.birthday << " - " << cur->st.score << endl;
            cur = cur->next;
        }
    }

    void printStudentByScore (double scoreTarget) {
        Node* cur = database->head;

        while (cur) {
            if (cur->st.score < scoreTarget)
            cout << cur->st.code << " - " << cur->st.name << " - " << cur->st.birthday << " - " << cur->st.score << endl;
            cur = cur->next;
        }
    }
};

void displayStudentDatabase() {
    // Initialize
    StudentDatabase database;
    cout << "Print the pre-initialize database" << endl;
    char code1[] = "1";
    char name1[] = "A";
    char birthday1[] = "06/03/2004";
    double score1 = 4;
    Student st1 = Student(code1, name1, birthday1, score1);

    char code2[] = "4";
    char name2[] = "B";
    char birthday2[] = "15/02/2004";
    double score2 = 10;
    Student st2 = Student(code2, name2, birthday2, score2);

    char code3[] = "3";
    char name3[] = "C";
    char birthday3[] = "15/01/2004";
    double score3 = 3.5;
    Student st3 = Student(code3, name3, birthday3, score3);

    char code4[] = "4";
    char name4[] = "D";
    char birthday4[] = "21/02/2004";
    double score4 = 6;
    Student st4 = Student(code4, name4, birthday4, score4);

    char code5[] = "2";
    char name5[] = "E";
    char birthday5[] = "21/02/1980";
    double score5 = 8;
    Student st5 = Student(code5, name5, birthday5, score5);

    database.addNewStudent(st1);
    database.addNewStudent(st2);
    database.addNewStudent(st3);
    database.addNewStudent(st4);
    database.printStudents();
    cout << "Print the students with code = 4" << endl;
    char code[] = "4";
    database.printStudentByCode(code);

    double score = 5;
    cout << "Print the students with score < 5" << endl;
    database.printStudentByScore(score);

    cout << "Create a new database and sort the code when adding." << endl;
    StudentDatabase databaseSorted;
    databaseSorted.addNewStudentByCode(st1);
    databaseSorted.addNewStudentByCode(st2);
    databaseSorted.addNewStudentByCode(st3);
    databaseSorted.addNewStudentByCode(st4);
    databaseSorted.addNewStudentByCode(st5);
    databaseSorted.printStudents();
}

int main() {
    displayStudentDatabase();
    return 0;
}