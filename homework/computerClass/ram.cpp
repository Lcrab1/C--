#include "ram.h"

RAM::RAM()
{
    cout << "RAM的无参构造函数被调用" << endl;
}
RAM::RAM(const RAM &ram)
{
    cout << "RAM的复制构造函数被调用" << endl;
}
RAM::~RAM()
{
    cout << "RAM的析构 函数被调用" << endl;
}
void RAM::Run()
{
    cout << "RAM的Run函数被调用" << endl;
}
void RAM::Stop()
{
    cout << "RAM的Stop函数被调用" << endl;
}