#include <iostream>
#include <vector>
#include <string>
#include "student.h"
using namespace std;

int main()
{
    Student s1, s2, s3, s4, s5;
    s1.Init("123", "Huy", 5.2, 6.7, 8.9, 5.2, 6.7, "Ho Chi Minh", "Nothing.");
    s2.Init("124", "Trinh", 5.2, 9, 8.9, 5.2, 8, "Ho Chi Minh", "Nothing.");
    s3.Init("126", "Neige", 5.2, 6.7, 2, 5.2, 6.7, "Ho Chi Minh", "Nothing.");
    s4.Init("125", "Ragnarick", 1.2, 6.7, 8.9, 5.2, 6.7, "Ho Chi Minh", "Nothing.");
    s5.Init("121", "Jeff", 5.2, 6.7, 8.9, 5.2, 6.7, "Ho Chi Minh", "Nothing.");
    StudentDatabase sd;
    sd.Init();
    sd.AddStudent(s1);
    sd.AddStudent(s2);
    sd.AddStudent(s3);
    sd.AddStudent(s4);
    sd.AddStudent(s5);
    sd.UpdateAverageScore();
    sd.SortByScoreDescending();
    sd.Output();
}
