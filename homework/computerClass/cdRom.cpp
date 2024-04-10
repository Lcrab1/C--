#include"cdRom.h"

CDROM::CDROM()
{
    cout << "CDROM的无参构造函数被调用" << endl;
}
CDROM::CDROM(const CDROM &cdrom)
{
    cout << "CDROM的复制构造函数被调用" << endl;
}
CDROM::~CDROM()
{
    cout << "CDROM的析构函数被调用" << endl;
}
void CDROM::Run()
{
    cout << "CDROM的Run函数被调用" << endl;
}
void CDROM::Stop()
{
    cout << "CDROM的Stop函数被调用" << endl;
}