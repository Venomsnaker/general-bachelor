#include <iostream>
#include <cstdlib> 
#include <time.h>
using namespace std;

// Task 1
long long get_fibo_recursive(long long x) {
    if (x <= 1) return x;
    return get_fibo_recursive(x - 1) + get_fibo_recursive(x - 2);
}

long get_fibo_iterative(long x) {
    long holder_two_back = 0, holder_one_back = 1;
    long cur = -1;

    if (x == 1) return 1;
    if (x == 0) return 0;

    while (x > 1) {
        cur = holder_two_back + holder_one_back;
        holder_two_back = holder_one_back;
        holder_one_back = cur;
        x--;
    }
    return cur;
}

void get_fibo_time_complexity(int test) {
    clock_t start;

    start = clock();
    cout << "Gia tri fibo cua so " << test << " la " << get_fibo_iterative(test) << endl;
    double time_taken = double(clock() - start) / (double)(CLOCKS_PER_SEC);
    cout << "Thoi gian thuc hien tuan tu la: " << time_taken << endl;

    start = clock();
    cout << "Gia tri fibo cua so " << test << " la " << get_fibo_recursive(test) << endl;
    time_taken = double(clock() - start) / (double)(CLOCKS_PER_SEC);
    cout << "Thoi gian thuc hien de qui la: " << time_taken << endl << endl;
}

// Task 2
long get_sequence_number_iterative(long x) {
    long holder_three_back = 1, holder_two_back = 2, holder_one_back = 5;
    long long cur = -1;
    if (x == 0) return holder_three_back;
    if (x == 1) return holder_two_back;
    if (x == 2) return holder_one_back;

    while (x > 2) {
        cur = holder_two_back + (holder_three_back * holder_one_back);
        holder_three_back = holder_two_back;
        holder_two_back = holder_one_back;
        holder_one_back = cur;
        x--;
    }
    return cur;
}

long get_sequence_number_recursive(long x) {
    if (x == 0) return 1;
    if (x == 1) return 2;
    if (x == 2) return 5;

    return get_sequence_number_recursive(x - 2) + (get_sequence_number_recursive(x - 3) * get_sequence_number_recursive(x - 1));
}

void get_sequence_number_time_complexity(int test) {
    clock_t start;

    start = clock();
    cout << "Gia tri day Fn den so " << test << " la " << get_sequence_number_iterative(test) << endl;
    double time_taken = double(clock() - start) / (double)(CLOCKS_PER_SEC);
    cout << "Thoi gian thuc hien tuan tu la: " << time_taken << endl;

    start = clock();
    cout << "Gia tri day Fn den so " << test << " la " << get_sequence_number_recursive(test) << endl;
    time_taken = double(clock() - start) / (double)(CLOCKS_PER_SEC);
    cout << "Thoi gian thuc hien de qui la: " << time_taken << endl << endl;
}

int main()
{
    get_fibo_time_complexity(35);
    get_sequence_number_time_complexity(35);
    return 0;
}

