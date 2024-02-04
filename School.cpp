#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include "Student.cpp"
#include "HighSchool.cpp"
#include "PrimarySchool.cpp"
#include "SchoolDAO.cpp"
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

enum {
    FINDID = 1, FINDNAME
};

enum {
    SORTID = 1, SORTNAME
};

class School : public SchoolDAO {
private:
    vector<Student*> studentAcc;
public:

    ~School() {
        for (auto& account : studentAcc) {
            delete account;
        }
    }

    void addStudent(Student* sAcc) {
        studentAcc.push_back(sAcc);
    }


    void viewStudent() {
        for (const auto& it : studentAcc) {
            try {
                it->output();
                cout << endl;
            }
            catch (const std::exception& e) {
                cerr << "Exception: " << e.what() << endl;
            }
        }

        cout << "Press any key to continue...";
        cin.ignore();
        cin.get();
    }


    void updateStudent(Student* account) {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID number" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case FINDID: {
            char performChoice;


            int IDNumber;
            cout << "Enter student ID: ";
            cin >> IDNumber;
            auto it = find_if(studentAcc.begin(), studentAcc.end(),
                [IDNumber](const Student* account) { return account->getId() == IDNumber; });
            do {
                if (it != studentAcc.end()) {
                    int choice;

                    cout << "==========EDIT MENU==========" << endl;
                    cout << "1.	ID number" << endl;
                    cout << "2.	Name" << endl;
                    cout << "3.	Gender" << endl; 
                    cout << "4. Back" << endl;
                    cout << "Enter choice(1-3)-> ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1: {
                        int new_id;
                        cout << "Enter new ID number: ";
                        cin >> new_id;

                        account->setId(new_id);
                        cout << "ID number is changed successfully" << endl;

                    }

                          break;
                    case 2: {
                        string new_name;
                        cout << "Enter new name: ";
                        cin >> new_name;

                        account->setName(new_name);
                        cout << "Name changed successfully" << endl;
                    }

                          break;
                    case 3:
                        char gender;
                        cout << "Enter gender: ";
                        cin >> gender;

                        account->setGender(gender);
                        cout << "Gender changed sucessfully" << endl;
                        break;
                    case 4: //break out to main menu
                        break;

                    default:
                        cout << "Invalid Choice. Please try again" << endl;
                        break;
                    }
                }
                else {
                    cout << "Student is not found" << endl;
                    cout << "Do you want to continue? (y/n) ->";
                    cin >> performChoice;
                }
            } while (performChoice == 'y' || performChoice == 'Y');

        }

                    break;
        case FINDNAME: {
            char performChoice;
            do {
                string name;
                cout << "Enter name: ";
                cin >> name;
                auto it = find_if(studentAcc.begin(), studentAcc.end(),
                    [name](const Student* account) { return account->getName() == name; });
                if (it != studentAcc.end()) {
                    int choice;
                    cout << "==========EDIT MENU==========" << endl;
                    cout << "1.	Account number" << endl;
                    cout << "2.	Name" << endl;
                    cout << "3.	Gender" << endl;
                    cout << "4. Back" << endl;
                    cout << "Enter choice(1-3)-> ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1: {
                        int new_num;
                        cout << "Enter new account number: ";
                        cin >> new_num;

                        account->setId(new_num);
                        cout << "Account number changed successfully" << endl;
                    }

                          break;
                    case 2: {
                        string new_name;
                        cout << "Enter new name: ";
                        cin >> new_name;

                        account->setName(new_name);
                        cout << "Name changed successfully" << endl;
                    }

                          break;
                    case 3: {
                        char gender;
                        cout << "Enter new gender: ";
                        cin >> gender;

                        account->setGender(gender);
                        cout << "Gender changed sucessfully" << endl;
                        break;
                    }
                        
                    case 4: //break out to main menu
                        break;

                    default:
                        cout << "Invalid Choice. Please try again" << endl;
                        break;
                    }
                }
                else {
                    cout << "Student is not found" << endl;
                    cout << "Do you want to continue? (y/n) -> ";
                    cin >> performChoice;
                }
            } while (performChoice == 'y' || performChoice == 'Y');

        }

                     break;
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }


    }


    void deleteStudent(Student* account) {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID number" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice) {
        case FINDID: {
            int IDNumber;
            cout << "Enter ID number: ";
            cin >> IDNumber;
            auto it = find_if(studentAcc.begin(), studentAcc.end(),
                [IDNumber](const Student* account) { return account->getId() == IDNumber; });
            if (it != studentAcc.end()) {
                // Display the information before deletion
                cout << "Student information to be deleted:\n";
                account->output();

                // Confirm deletion
                cout << "Do you want to delete this student? (y/n): ";
                char choice;
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    // Perform deletion
                    auto iter = find(studentAcc.begin(), studentAcc.end(), account);
                    studentAcc.erase(iter);
                    cout << "Student is deleted successfully.\n";

                }
                else {
                    cout << "Deletion canceled.\n";

                }
            }
            else {
                cout << "Student is not found" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
            }


        }

                    break;
        case FINDNAME: {
            string name;
            cout << "Enter name: ";
            cin >> name;
            auto it = find_if(studentAcc.begin(), studentAcc.end(),
                [name](const Student* account) { return account->getName() == name; });
            if (it != studentAcc.end()) {
                // Display the information before deletion
                cout << "Student information to be deleted:\n";
                account->output();

                // Confirm deletion
                cout << "Do you want to delete this student? (y/n): ";
                char choice;
                cin >> choice;

                if (choice == 'y' || choice == 'Y') {
                    // Perform deletion
                    auto iter = find(studentAcc.begin(), studentAcc.end(), account);
                    studentAcc.erase(iter);
                    cout << "Student is deleted successfully.\n";

                }
                else {
                    cout << "Deletion canceled.\n";

                }
            }
            else {
                cout << "Student is not found" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
            }
        }

                     break;

        case 3:
            break;

        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue...";
            cin.ignore();
            cin.get();
            break;
        }
    }

    void sortStudent() {
        int choice;
        cout << "==========SORT MENU==========" << endl;
        cout << "1. Sort by ID number" << endl;
        cout << "2. Sort by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;
        switch (choice)
        {
        case SORTID: {
            int choice;
            cout << "==========SORT METHOD==========" << endl;
            cout << "1. Sort by Ascending" << endl;
            cout << "2. Sort by Descending" << endl;
            cout << "3. Back to main menu" << endl;
            cout << "Enter choice(1-3) -> ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                sort(studentAcc.begin(), studentAcc.end(), [](const Student* a, const Student* b) {
                    return a->getId() < b->getId();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                sort(studentAcc.begin(), studentAcc.end(), [](const Student* a, const Student* b) {
                    return a->getId() > b->getId();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            }

        }
                    break;
        case SORTNAME: {
            int choice;
            cout << "==========EDIT METHOD==========" << endl;
            cout << "1. Sort by Ascending" << endl;
            cout << "2. Sort by Descending" << endl;
            cout << "3. Back to main menu" << endl;
            cout << "Enter choice(1-3) -> ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                sort(studentAcc.begin(), studentAcc.end(), [](const Student* a, const Student* b) {
                    return a->getName() < b->getName();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            case 2:
                sort(studentAcc.begin(), studentAcc.end(), [](const Student* a, const Student* b) {
                    return a->getName() > b->getName();
                    });
                cout << "Sorting";
                DotDotDot();
                cout << "Sorted successfully" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            default:
                cout << "Invalid choice." << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
                break;
            }
        }
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.get();
            break;
        }
    }

    void searchStudent(Student* account) {
        int choice;
        cout << "==========FIND MENU==========" << endl;
        cout << "1. Find by ID number" << endl;
        cout << "2. Find by name" << endl;
        cout << "3. Back to main menu" << endl;
        cout << "Enter choice(1-3)-> ";
        cin >> choice;;
        switch (choice)
        {
        case FINDID: {
            int IDNumber;
            cout << "Enter ID number: ";
            cin >> IDNumber;
            auto it = find_if(studentAcc.begin(), studentAcc.end(),
                [IDNumber](const Student* account) { return account->getId() == IDNumber; });
            if (it != studentAcc.end()) {
                cout << "Student found:\n";
                account->output();  // Output the details of the found account
                cout << "Press any key to continue...";
                cin.ignore();
                cin.get();
            }
            else {
                cout << "Student info not found" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
            }

        }
                    break;
        case FINDNAME: {
            string name;
            cout << "Enter name: ";
            cin >> name;
            auto it = find_if(studentAcc.begin(), studentAcc.end(),
                [name](const Student* account) { return account->getName() == name; });
            if (it != studentAcc.end()) {
                cout << "Account found:\n";
                account->output();  // Output the details of the found account
                cout << "Press any key to continue...";
                cin.ignore();
                cin.get();
            }
            else {
                cout << "Student info not found" << endl;
                cout << "Press any key to continue..." << endl;
                cin.ignore();
                cin.get();
            }

        }
        default:
            cout << "Invalid choice." << endl;
            cout << "Press any key to continue..." << endl;
            cin.ignore();
            cin.get();
            break;

        }
    }

    void saveStudent() {
        ofstream outputFile("Student.dat", ios::out | ios::binary);

        if (!outputFile.is_open()) {
            cout << "Error in creating file...\n";
            exit(1);
        }
        else {
            for (const auto& accountPtr : studentAcc) {
                outputFile.write(reinterpret_cast<char*>(accountPtr), sizeof(Student));
            }

            cout << "File saved successfully" << endl;
        }

        outputFile.close();
    }


    void loadStudent() {
        ifstream inputFile("Student.dat", ios::in | ios::binary);

        if (!inputFile.is_open()) {
            cout << "Error in opening file...\n";
            exit(1);
        }

        try {
            while (true) {
                Student* account = new Student();
                if (!inputFile.read(reinterpret_cast<char*>(account), sizeof(Student))) {
                    // Reached end of file
                    delete account;  // Clean up the dynamically allocated memory
                    break;
                }

                addStudent(account);
                cout << "File loaded successfully" << endl;
            }
        }
        catch (const std::exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }

        inputFile.close();
    }


    void DotDotDot() {
        for (int i = 0; i < 5; i++) {
            cout << ".";
            cout.flush();
            this_thread::sleep_for(chrono::milliseconds(500));
        }

    }



};