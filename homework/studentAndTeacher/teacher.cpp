#include <iostream>
#include <string>
using namespace std;
#include "student.h"
#include "teacher.h"

Teacher::Teacher(string tid, string tname, string tsex, short tage)
{
    id = tid;
    name = tname;
    sex = tsex;
    age = tage;
}

void Teacher::display()
{
    cout << "���֤��: " << id << endl;
    cout << "����: " << name << endl;
    cout << "�Ա�: " << sex << endl;
    cout << "����: " << age << endl;
}
