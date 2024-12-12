#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct student {
    string name;
    int rollNo;
    int regno;
    string program;
};

void createStudent(vector<student>& students){
    student newStudent;

    cout << "\n Enter Student name: ";
    cin.ignore();
    getline(cin, newStudent.name);

    cout << "Enter Roll No: ";
    cin >> newStudent.rollNo;

    cout << "Enter Program name: ";
    cin >> newStudent.program;

    cout << "Enter Registration no: ";
    cin >> newStudent.regno;

    // Push New student to Studens
    students.push_back(newStudent);
    cout << "\n Student Create Successfull \n";
    cout << "------------------------------";
}

void displayStudents(vector<student>& students){
    if(students.empty()){
        cout << "\n No student Avalable in system";
        return;
    }

    cout << " \n -- All student records -- \n ";

    for (const auto &student : students){
        cout << "name; " << student.name << ", Roll No; " << student.rollNo << ",Program name: " << student.program << ",Registration No: " << student.regno << endl;
    };
}

void updateStudent(vector<Student>& students) {
    int rollNo;
    cout << "\nEnter roll number of the student to update: ";
    cin >> rollNo;

    bool found = false;
    for (auto& student : students) {
        if (student.rollNo == rollNo) {
            found = true;
            cout << "Enter new name: ";
            cin.ignore();  // To ignore the leftover newline character
            getline(cin, student.name);

            cout << "Enter new marks: ";
            cin >> student.marks;

            cout << "Student record updated successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNo << " not found.\n";
    }
}