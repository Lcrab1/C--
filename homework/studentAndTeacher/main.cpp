#include <iostream>
using namespace std;
#include "student.h"
#include "teacher.h"

int Student::count = 0;

int main()
{
    Student st1(2402100345, "王五", "女");
    st1.display();
    st1.showCount();

    Student st2(2402100480, "李四", "男");
    st2.display();
    st2.showCount();

    Teacher t1("610111199909099999", "Jack", "M", 30);
    t1.display();
    system("PAUSE");
    return 0;
}
