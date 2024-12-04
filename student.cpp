//
// Created by kevin on 2024-11-13.
//
#include "student.h"
#include <iostream>
#include <iomanip>
using namespace std;

Student::Student(string fn, string ln, string sid, double mt1, double mt2, double fg) {
    firstName = fn;
    lastName = ln;
    studentId = sid;
    midTerm1 = mt1;
    midTerm2 = mt2;
    finalsGrade = fg;
    //averageGrade = avg;
}

void Student::display() {
    cout << setw(15) << firstName
         << setw(15) << lastName
         << setw(15) << studentId
         << setw(10) << midTerm1
         << setw(10) << midTerm2
         << setw(10) << finalsGrade ;
         

}









