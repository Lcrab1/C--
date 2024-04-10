#include "computer.h"
#include <Windows.h>
Computer::Computer()
{
    memset(&m_CPU, 0, sizeof(m_CPU));
    memset(&m_Ram, 0, sizeof(m_Ram));
    memset(&m_CDROM, 0, sizeof(m_CDROM));
    cout << "Computer的无参构造函数被调用" << endl;
}
Computer::~Computer()
{
    cout << "Computer的析构函数被调用" << endl;
}
void Computer::Run()
{
    cout << "Computer的Run函数被调用" << endl;
    m_CPU.Run();
    m_Ram.Run();
    m_CDROM.Run();
}
void Computer::Stop()
{
    cout << "Computer的Stop函数被调用" << endl;
    m_CPU.Stop();
    m_Ram.Stop();
    m_CDROM.Stop();
}