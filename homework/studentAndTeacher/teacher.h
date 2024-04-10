#include <string>
using namespace std;
class Teacher
{
public:
    Teacher(string tid = "", string tname = "", string tsex = "", short tage = 0);
    void display();

private:
    string id;   //身份证号
    string name; //姓名
    string sex;  //性别
    short age;   //年龄
};
