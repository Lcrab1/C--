#include <string>
using namespace std;
class Student
{
public:
    Student(unsigned long snumber = 0, string sname = "", string ssex = "");
    Student(const Student &other);
    void display();
    ~Student();
    static void showCount();

private:
    unsigned long number;
    string name;
    string sex;
    static int count;
};
