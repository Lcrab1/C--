#include <iostream>
#include <string>
using namespace std;
#include "student.h"

Student::Student(unsigned long snumber, string sname, string ssex)
{
    number = snumber;
    name = sname;
    sex = ssex;
    count++;
}

Student::Student(const Student &other)
{
    number = other.number;
    name = other.name;
    sex = other.sex;
    count++;
}
void Student::display()
{
    cout << "学号: " << number << endl;
    cout << "姓名: " << name << endl;
    cout << "性别: " << sex << endl;
}

Student::~Student()
{
    --count;
}

void Student::showCount()
{
    cout << "当前学生总人数为:" << count << endl;
}