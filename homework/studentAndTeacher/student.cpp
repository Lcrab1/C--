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
    cout << "ѧ��: " << number << endl;
    cout << "����: " << name << endl;
    cout << "�Ա�: " << sex << endl;
}

Student::~Student()
{
    --count;
}

void Student::showCount()
{
    cout << "��ǰѧ��������Ϊ:" << count << endl;
}