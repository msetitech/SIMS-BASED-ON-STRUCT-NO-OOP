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