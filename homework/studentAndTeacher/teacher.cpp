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
    cout << "身份证号: " << id << endl;
    cout << "姓名: " << name << endl;
    cout << "性别: " << sex << endl;
    cout << "年龄: " << age << endl;
}
