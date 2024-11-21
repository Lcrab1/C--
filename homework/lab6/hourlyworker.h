#include "employee.h"
class HourlyWorker:public Employee
{

private:
    double wage;
    unsigned int hours;
public:
    HourlyWorker(std::string name,double wage,unsigned int hours);
    void SetWage(double wage);
    void SetHours(unsigned int hours);
    std::string Show() override;
    double Earnings() override;
};