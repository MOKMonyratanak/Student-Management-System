#pragma once
#include <iostream>
#include "Student.cpp"
#include "DataInputValidation.cpp"
#include <iomanip>
using namespace std;

class PrimarySchool : public Student {
private:
    int schoolfee;
public:
    PrimarySchool() : Student() {
        schoolfee = 0;
    }

    PrimarySchool(int account_number, string name, char gender, int schoolfee) : Student(account_number, name, gender) {
        setSchoolfee(schoolfee);
    }

    void setSchoolfee(const int schoolfee) {
        if (schoolfee > 0) {
            this->schoolfee = schoolfee;
        }
        else {
            throw BadInputException();
        }
    }
    int getSchoolfee() const {
        return schoolfee;
    }

    //might delete this function
    void input() {
        double fee;
        Student::input();
        setSchoolfee(500);
    }

    void output() override {
        cout << "Primary School Student: " << endl;
        cout << "-------------------------------------------------------------------\n";
        cout << "ID          Name                  Gender            Grade Level \n";
        cout << "-------------------------------------------------------------------\n";
        Student::output();
        cout << setw(18) << getSchoolfee() << endl;
    }
};