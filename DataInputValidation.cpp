#pragma once
#include <iostream>

using namespace std;

class DataInputValidation {
private:
    bool validate_num(int num) {
        if (cin.fail() || num > 1000000) {
            return false;
        }
        return true;
    }

    bool validate_name(string name) {
        if (name.length() > 10) {
            return false;
        }

        for (int i = 0; i < name.length(); i++) {
            if (!(name[i] >= 65 && name[i] <= 122)) {
                return false;
            }
        }
        return true;
    }

    bool validate_gender(char gender) {
        if (gender == 'f' || gender == 'F' || gender == 'M' || gender == 'm') {
            return true;
        }
        else {
            return false;
        }
    }

public:

    int input_id() {
        int num;
        while (true) {
            cout << "Enter student ID: ";
            cin >> num;
            if (!validate_num(num)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid Input" << endl;
            }
            else {
                return num;
            }
        }
    }

    double input_gender() {
        char gender;
        while (true) {
            cout << "Enter gender: ";
            cin >> gender;
            if (!validate_gender(gender)) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Error: Invalid Input" << endl;
            }
            else {
                return gender;
            }
        }
    }

    string input_name() {
        string name;
        while (true)
        {
            cout << "Enter student name: ";
            cin >> name;
            if (!validate_name(name)) {
                cout << "Error: Invalid/max letter reached" << endl;
            }
            else {
                return name;
            }
        }

    }

};
