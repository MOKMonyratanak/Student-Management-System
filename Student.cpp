#pragma once
#include <iostream>
#include <iomanip>
#include "DataInputValidation.cpp"
#include "BadInputException.cpp"
using namespace std;

class Student {
protected:
    int id;
    string name;
    char gender;
    DataInputValidation val;

public:
    Student() {
        id = 0;
        name = "unknown";
        gender = 'X';
    }

    Student(int id, string name, char gender) {
        setId(id);
        setName(name);
        setGender(gender);
    }



    void setId(const int id) {
        if (id > 0) {
            this->id = id;
        }
        else {
            throw BadInputException();
        }
    }
    int getId() const {
        return id;
    }

    void setName(const string name) {
        if (!name.empty()) {
            this->name = name;
        }
        else {
            throw BadInputException();
        }
    }
    string getName() const {
        return this->name;
    }

    void setGender(const char gender) {
        if (gender > 0) {
            this->gender = gender;
        }
        else {
            throw BadInputException();
        }
    }
    char getGender() const {
        return gender;
    }

    virtual void output() {

        cout << setw(8) << getId() << setw(16) << getName() << setw(2) << getGender();
    }

    virtual void input() {
        int number;
        string name;
        char gender;

        number = val.input_id();
        setId(number);

        name = val.input_name();
        setName(name);

        gender = val.input_gender();
        setGender(gender);

    }


};