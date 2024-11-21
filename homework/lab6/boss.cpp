#include "boss.h"
Boss::Boss(const std::string &name, const double weeklySalary)
    : Employee(name), weeklySalary(weeklySalary)
{
}
void Boss::SetWeeklySalary(double salary)
{
    weeklySalary = salary;
}
std::string Boss::Show()
{
    return std::string("Boss ") += GetName();
}
double Boss::Earnings()
{
    return weeklySalary;
}