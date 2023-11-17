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

void insertByProducedYear(LinkedList &l, Movie* movie) {
    Movie* temp = l.head;

    if (!temp) l.head = l.tail = movie;
    else {
        if (temp->year_produced > movie->year_produced) {
            movie->next = temp;
            l.head = movie;
            return;
        }

        while (temp->next) {
            if (temp->next->year_produced > movie->year_produced) {
                movie->next = temp->next;
                temp->next = movie;
                return;
            }
            temp = temp->next;
        }
        temp->next = movie;
    }
}

void deleteHBOMovies(LinkedList &l) {
    Movie* prev = new Movie;
    prev->next = l.head;

    while(prev->next) {
        if (strcmp(prev->next->producer, "HBO") == 0) {
            prev->next = prev->next->next;
            continue;
        }
        prev = prev->next;
    }
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