#pragma once
#include <iostream>
#include "Student.cpp"
#include "DataInputValidation.cpp"
#include <iomanip>

using namespace std;

class HighSchool : public Student {
private:
    int schoolfee;
public:
    HighSchool() : Student() {
        schoolfee = 0;
    }

    HighSchool(int id, string name, double balance, int schoolfee) : Student(id, name, gender) {
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

    void input() {
        double schoolfee;
        Student::input();
        setSchoolfee(1000);
    }

    void output()override {
        cout << "High School Student: " << endl;
        cout << "-------------------------------------------------------------------\n";
        cout << "ID          Name                  Gender            Grade Level \n";
        cout << "-------------------------------------------------------------------\n";
        Student::output();
        cout << setw(18) << getSchoolfee() << endl;
    }

};

