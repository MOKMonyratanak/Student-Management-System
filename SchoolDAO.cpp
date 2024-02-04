#include <iostream>
#include "Student.cpp"
using namespace std;

class SchoolDAO {
public:
	virtual void addStudent(Student* account) = 0;
	virtual void viewStudent() = 0;
	virtual void updateStudent(Student* account) = 0;
	virtual void deleteStudent(Student* account) = 0;
	virtual void sortStudent() = 0;
	virtual void searchStudent(Student* account) = 0;
	virtual void saveStudent() = 0;
};