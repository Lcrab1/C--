#include<iostream>
#include"cpu.h"
#include"ram.h"
#include"cdRom.h"
using namespace std;

class Computer
{
    private:
        CPU m_CPU;
        RAM m_Ram;
        CDROM m_CDROM;
    public:
        Computer();
        ~Computer();
        void Run();
        void Stop();
};
