//
// Created by kevin on 2024-11-13.
//

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;
class Student {
private:
    string firstName;
    string lastName;
    string studentId;
    double midTerm1;
    double midTerm2;
    double finalsGrade;
    //double averageGrade;


public:
    //Constructor
    Student(string fn, string ln, string sid, double mt1, double mt2, double fg);

    //Getters
    string getFirstName(){return firstName;}
    string getLastName() { return lastName; }
    string getStudentId() { return studentId; }
    double getMidTerm1() {return midTerm1; }
    double getMidTerm2() {return midTerm2; }
    double getFinalsGrade() {return finalsGrade; }




    void display(); //Method to display the student's information.







};


#endif //STUDENT_H
