#include "hourlyworker.h"

HourlyWorker::HourlyWorker(std::string name, double wage, unsigned int hours)
    : Employee(name), wage(wage), hours(hours)
{
}
void HourlyWorker::SetWage(double wage)
{
    wage = wage;
}
void HourlyWorker::SetHours(unsigned int hours)
{
    hours = hours;
}
std::string HourlyWorker::Show()
{
    return std::string("HourlyWorker ") += GetName();
}
double HourlyWorker::Earnings()
{
    return wage * hours;
}