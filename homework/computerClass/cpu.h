#include <iostream>
using namespace std;
// CPU Rank
enum CPU_Rank
{
    P1 = 1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7
};

class CPU
{
private:
    CPU_Rank m_Rank;
    // frequency单位为MHz
    int m_Frequency;
    // voltage单位为V
    float m_Voltage;

public:
    //无参构造函数
    CPU();
    //复制构造函数
    CPU(const CPU &cpu);
    //析构函数
    ~CPU();
    //运行CPU
    void Run();
    //停止CPU
    void Stop();
    //设置rank
    void SetRank(CPU_Rank rank);
    //得到rank();
    CPU_Rank GetRank();
    //设置Frequency
    void SetFrequency(int frequency);
    //得到Frequency();
    int GetFrequency();
    //设置Voltage
    void SetVoltage(float voltage);
    //得到Voltage();
    float GetVoltage();
};