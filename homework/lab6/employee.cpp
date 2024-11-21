#include "Employee.h"

Employee::Employee()
{
}
Employee::Employee(const std::string &name)
    : name(name)
{
}
const std::string &Employee::GetName()
{
    return name;
}