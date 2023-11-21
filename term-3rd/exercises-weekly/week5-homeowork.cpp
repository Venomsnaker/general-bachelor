#include <iostream>
#include <cstring>
using namespace std;

struct Movie {
    char id[10];
    char name[30];
    char producer[30];
    int year_produced;
    float ranking;

    Movie* next;
};

struct LinkedList {
    Movie* head;
    Movie* tail;
};

void initLinkedList(LinkedList &l) {
    l.head = NULL;
    l.tail = NULL;
}

void updateListTail(LinkedList &l) {
    Movie* temp = l.head;

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

Movie* createMovie(const char* id, const char* name, const char* producer, int year_produced, float ranking) {
    Movie* movie = new Movie;
    strcpy(movie->id, id);
    strcpy(movie->name, name);
    strcpy(movie->producer, producer);
    movie->year_produced = year_produced;
    movie->ranking = ranking;
    movie->next = NULL;
    return movie;
}

void addFront(LinkedList &l, Movie* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        p->next = l.head;
        l.head = p;
    }
    return;
}

void addBack(LinkedList &l, Movie* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        l.tail->next = p;
        l.tail = p;
    }
    return;
}

void insertByProducedYear(LinkedList &l, Movie* p) {
    if (l.head == NULL) l.head = l.tail = p;
    else {
        if (p->year_produced < l.head->year_produced) {
            addFront(l, p);
            return;
        }

        if (p->year_produced > l.tail->year_produced) {
            addBack(l, p);
            return;
        }

        Movie* temp = l.head;

        while (temp->next != NULL && p->year_produced > temp->next->year_produced) {
            temp = temp->next;
        }
        p->next = temp->next;
        temp->next = p;
        return;
    }
}

void deleteHBOMovies(LinkedList &l) {
    if (l.head == NULL) return;

    Movie* dummy = createMovie("","","",0,0);
    dummy->next = l.head;
    Movie* curr = l.head;
    Movie* prev = dummy;

    while (curr != NULL) {
        if (strcmp(curr->producer, "HBO") == 0) {
            while(curr != NULL && strcmp(curr->producer, "HBO") == 0) {
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

void printAllMovies(LinkedList l) {
    Movie* temp = l.head;

    while(temp) {
        cout << "Id " << temp->id << " - Name " << temp->name << " - Produced Year " << temp->year_produced << " - Producer " << temp->producer << " - Ranking " << temp->ranking << endl;
        temp = temp->next;
    }
    return;
}

void visualizeLinkedList() {
    LinkedList l;
    initLinkedList(l);

    char id1[] = "1";
    char name1[] = "Hannibal";
    char producer1[] = "HBO";
    int year_produced1 = 2013;
    float ranking1 = 9.6;

    char id2[] = "2";
    char name2[] = "Game Of Thrones";
    char producer2[] = "HBO";
    int year_produced2 = 2011;
    float ranking2 = 8.1;

    char id3[] = "3";
    char name3[] = "Coco";
    char producer3[] = "Pixar";
    int year_produced3 = 2017;
    float ranking3 = 7.9;

    char id4[] = "4";
    char name4[] = "Matrix";
    char producer4[] = "Warner Bros.";
    int year_produced4 = 2003;
    float ranking4 = 4.9;

    char id5[] = "5";
    char name5[] = "Mulan";
    char producer5[] = "Disney";
    int year_produced5 = 1998;
    float ranking5 = 7.1;

    cout << "Print the initialize database (intput by id while sort by year_produced)." << endl;
    insertByProducedYear(l, createMovie(id1, name1, producer1, year_produced1, ranking1));
    insertByProducedYear(l, createMovie(id2, name2, producer2, year_produced2, ranking2));
    insertByProducedYear(l, createMovie(id3, name3, producer3, year_produced3, ranking3));
    insertByProducedYear(l, createMovie(id4, name4, producer4, year_produced4, ranking4));
    insertByProducedYear(l, createMovie(id5, name5, producer5, year_produced5, ranking5));
    printAllMovies(l);
    cout << endl;
    cout << "Delete all HBO movies." << endl;
    deleteHBOMovies(l);
    printAllMovies(l);
    return;
}

int main() {
    visualizeLinkedList();
    return 0;
}