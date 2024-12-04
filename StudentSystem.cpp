//
// Created by kevin on 2024-11-20.
//

#include "StudentSystem.h"
#include <iostream>
#include <algorithm>
#include <iomanip>


// Displays the main menu options
void StudentSystem::showMenu(){
    cout <<  "\n Student System Menu" <<endl;
    cout << "1. Add New Student" <<endl;
    cout << "2. Show all students" <<endl;
    cout << "3. Show Students Alphabetically" <<endl;
    cout << "4. Find Student" <<endl;
    cout << "5. Remove Student" << endl;
    cout << "6. Clear All Students" << endl;
    cout << "7. Set Grade Weights" << endl;
    cout << "8. Exit" <<endl;

}
// Main program loop that handles user input
void StudentSystem::start() {
    int choice;
    while(true) {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: addStudent();
            break;
            case 2: showAllStudents();
            break;
            case 3: showSortedStudents();
            break;
            case 4: findStudent();
            break;
            case 5: removeStudent();
            break;
            case 6: clearAllStudents();
            break;
            case 7: setWeights();
            break;
            case 8: return;
            default: cout << "Invalid choice!!!";

        }
    }
}
// Adds new student to the system
void StudentSystem::addStudent() {
    string fn, ln, sid;
    double mt1, mt2, fg;

    cout << "Enter first name: ";
    cin >> fn;
    cout << "Enter last name: ";
    cin >> ln;
    cout << "Enter student ID number: ";
    cin >> sid;
    cout << "Enter grade for midterm 1: ";
    cin >> mt1;
    cout << "Enter grade for midterm 2: ";
    cin >> mt2;
    cout << "Enter grade for final: ";
    cin >> fg;

    students.emplace_back(fn, ln, sid, mt1, mt2, fg);
    cout << "Student added successfully!"<<endl;
}

// Displays all the students in the system and also shows letter grade.
void StudentSystem::showAllStudents() {

    if (students.empty()) {
        cout << "No Students in system." << endl;
        return;
    }

    cout << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(15) << "Student #"
         << setw(10) << "Midterm1"
         << setw(10) << "Midterm2"
         << setw(10) << "Final"
         << setw(10) << "Grade" << endl;

    for(auto& student : students) {
        student.display();
        double avg = student.getMidTerm1() * mt1Weight +
                     student.getMidTerm2() * mt2Weight +
                     student.getFinalsGrade() * finalWeight;
        cout << setw(10) << calculateGrade(avg) << endl;
    }
}
// Shows students listed alphabetically
void StudentSystem::showSortedStudents() {

    if(students.empty()){
        cout << "No Students in the System!";
        return;
    }

    vector<Student> sorted = students;

    sort(sorted.begin(), sorted.end(),
              [](Student& a, Student& b) {
                  if(a.getLastName() == b.getLastName())
                      return a.getFirstName() < b.getFirstName();
                  return a.getLastName() < b.getLastName();
              });

    cout << "\nSorted students:\n";
    cout << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(15) << "Student #"
         << setw(10) << "Midterm1"
         << setw(10) << "Midterm2"
         << setw(10) << "Final" << endl;
    for(auto& student : sorted) {
        student.display();
        cout << endl;
    }

}
// Finds a student by student ID
void StudentSystem::findStudent() {
    if(students.empty()) {
        cout << "No students in the system." << endl;
    }

    string id;
    cout << "Enter the student ID: ";
    cin >> id;

    cout << setw(15) << "First Name"
         << setw(15) << "Last Name"
         << setw(15) << "Student #"
         << setw(10) << "Midterm1"
         << setw(10) << "Midterm2"
         << setw(10) << "Final" << endl;

    for(auto& student : students) {
        if(student.getStudentId() == id) {
            student.display();
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Removes a student by ID
void StudentSystem::removeStudent() {
    if(students.empty()) {
        cout << "No students in the system." <<endl;
        return;
    }

    string id;
    cout << "Enter the student ID: " <<endl;
    cin >> id;

    for(auto it = students.begin(); it != students.end(); ++it){
        if (it -> getStudentId() == id) {
            students.erase(it);
            cout << "Student removed." << endl;
            return;
        }
    }
    cout << "Student not found." << endl;
}

// Clears all the student data in the system
void StudentSystem::clearAllStudents() {
    students.clear();
    cout << "Student system has been cleared, all students removed." <<endl;
}
// Set the weights for grade calculation
void StudentSystem::setWeights() {
    cout << "Enter the values you wish to change the weights to.(Must add up to 1): ";
    cin >> mt1Weight >> mt2Weight >> finalWeight;

    if(mt1Weight + mt2Weight + finalWeight != 1.0) {
        cout << "Weights must equal 1. Reverting to defaults." << endl;
        mt1Weight = .25;
        mt2Weight = .25;
        finalWeight = .50;
    }
}
// Calculates the letter grade based on number average.
char StudentSystem::calculateGrade(double average) {
    if ( average > 90)
        return 'A';
    if ( average >= 80)
        return 'B';
    if ( average >= 70)
        return 'C';
    if ( average >= 60)
        return 'D';
    return 'F';
}

