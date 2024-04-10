#include "cpu.h"

CPU::CPU()
{
    m_Rank = P1;
    m_Frequency = 0;
    m_Voltage = 0;
    cout << "CPU的无参构造函数被调用" << endl;
}

//复制构造函数
CPU::CPU(const CPU &cpu)
{
    m_Rank = cpu.m_Rank;
    m_Frequency = cpu.m_Frequency;
    m_Voltage = cpu.m_Voltage;
    cout << "CPU的复制构造函数被调用" << endl;
}

//析构函数
CPU::~CPU()
{
    cout << "CPU析构函数被调用" << endl;
}

//运行CPU
void CPU::Run()
{
    cout << "CPU的Run函数被调用" << endl;
}
//停止CPU
void CPU::Stop()
{
    cout << "CPU的Stop函数被调用" << endl;
}
//设置rank
void CPU::SetRank(CPU_Rank rank)
{
    m_Rank = rank;
}
//得到rank();
CPU_Rank CPU::GetRank()
{
    return m_Rank;
}
//设置Frequency
void CPU::SetFrequency(int frequency)
{
    m_Frequency = frequency;
}
//得到Frequency();
int CPU::GetFrequency()
{
    return m_Frequency;
}
//设置Voltage
void CPU::SetVoltage(float voltage)
{
    m_Voltage = voltage;
}
//得到Voltage();
float CPU::GetVoltage()
{
    return m_Voltage;
}