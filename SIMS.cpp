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



void updateStudent(vector<student>& students) {
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

            cout << "Enter new regno: ";
            cin >> student.regno;

            cout << "Student record updated successfully.\n";
            break;
        }
    }

    if (!found) {
        cout << "Student with roll number " << rollNo << " not found.\n";
    }
}


// Function to delete a student record by roll number
void deleteStudent(vector<student>& students) {
    int rollNo;
    cout << "\nEnter roll number of the student to delete: ";
    cin >> rollNo;

    auto it = students.begin();
    bool found = false;
    while (it != students.end()) {
        if (it->rollNo == rollNo) {
            found = true;
            students.erase(it);
            cout << "Student record deleted successfully.\n";
            break;
        }
        ++it;
    }

    if (!found) {
        cout << "Student with roll number " << rollNo << " not found.\n";
    }
}

// Main menu function
void showMenu() {
    cout << "\nStudent Management System\n";
    cout << "1. Create Student Record\n";
    cout << "2. View All Student Records\n";
    cout << "3. Update Student Record\n";
    cout << "4. Delete Student Record\n";
    cout << "5. Exit\n";
}

int main() {
    vector<student> students;
    int choice;

    while (true) {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                createStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                updateStudent(students);
                break;
            case 4:
                deleteStudent(students);
                break;
            case 5:
                cout << "Exiting system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}