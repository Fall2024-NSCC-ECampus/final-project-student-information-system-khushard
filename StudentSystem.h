//
// Created by kevin on 2024-11-20.
//

#ifndef STUDENTSYSTEM_H
#define STUDENTSYSTEM_H
#include <vector>
#include "Student.h"

class StudentSystem {

private:
    vector<Student> students;

    double mt1Weight = 0.25, mt2Weight = 0.25, finalWeight = 0.5;

public:
    static void showMenu();
    void start();
    void addStudent();
    void showAllStudents();
    void showSortedStudents();
    void findStudent();
    void removeStudent();
    void clearAllStudents();
    void setWeights();
    static char calculateGrade(double average);
    void displayHeader();




};



#endif //STUDENTSYSTEM_H
