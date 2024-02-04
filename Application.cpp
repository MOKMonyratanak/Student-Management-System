#pragma once

#include <iostream>
#include "School.cpp"
#include "HighSchool.cpp"
#include "PrimarySchool.cpp"
#include "Login&Register.cpp"

using namespace std;

enum {
    ADDSTUDENT = 1,
    DISPLAYSTUDENT,
    UPDATESTUDENT,
    DELETESTUDENT,
    SORTSTUDENT,
    SEARCHSTUDENT,
    SAVESTUDENT,
    LOGOUT

};

class Application {
private:

    School s;
    Student* account{};

    void studentMenu() {
        cout << "==========Student Management Menu==========" << endl;
        cout << "1. Add new student" << endl;
        cout << "2. View all students" << endl;
        cout << "3. Update a specific student details" << endl;
        cout << "4. Delete a specific student" << endl;
        cout << "5. Sort student list" << endl;
        cout << "6. Search for a specific student" << endl;
        cout << "7. Save student information" << endl;
        cout << "8. Log out" << endl;
    }

    void authenticationMenu() {
        cout << "==========Student Management System==========" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;
    }


    int getChoice() {
        int choice;

        cout << "Enter your choice(1-8)-> ";
        cin >> choice;
        return choice;

    }


public:

    void studentManagement() {

        int choice = 0;
        int option = 0;


        do {
            studentMenu();
            choice = getChoice();

            switch (choice) {
            case ADDSTUDENT: {
                cout << "1. High school student" << endl;
                cout << "2. Primary school student" << endl;
                cout << "Which grade level is the student?(1-2)-> ";
                cin >> option;

                switch (option) {
                case 1: {
                    auto savingAccount = make_unique<HighSchool>();
                    savingAccount->input();
                    s.addStudent(savingAccount.release());
                    break;
                }
                case 2:
                {
                    auto checkingAccount = make_unique<PrimarySchool>();
                    checkingAccount->input();
                    s.addStudent(checkingAccount.release());
                    break;

                }

                default:
                    cout << "Invalid Account type" << endl;
                    cout << "Press any key to contine..." << endl;
                    cin.ignore();
                    cin.get();
                    studentManagement();
                    break;
                }
                cout << "Bank account created successfully." << endl;
                break;
            }

            case DISPLAYSTUDENT:
                s.viewStudent();
                break;

            case UPDATESTUDENT: {
                s.updateStudent(account);
                break;
            }

            case DELETESTUDENT:
                s.deleteStudent(account);
                break;

            case SORTSTUDENT:
                s.sortStudent();
                break;

            case SEARCHSTUDENT:
                s.searchStudent(account);
                break;
            case SAVESTUDENT:
                s.saveStudent();
                break;
                break;
            case LOGOUT:
                break;

            default:
                cout << "Invalid Choice, Try again" << endl;
                break;
            }

        } while (choice != 8);
    }

    void run() {
        int choice = 0;
        Login log;


        do {

            authenticationMenu();
            choice = getChoice();
            switch (choice)
            {
            case 1:
                if (log.userLogin() == true) {
                    system("cls");
                    s.loadStudent();
                    studentManagement();
                }
                else {
                    cout << "Login failed. Please try again." << endl;
                }
                break;
            case 2:
                log.userRegister();
                break;
            case 3:
                exit(1);

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
            }


        } while (choice != 0);
    }

};







