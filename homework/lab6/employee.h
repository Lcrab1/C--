#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee
{
private:
    std::string name;

public:
    Employee();
    Employee(const std::string &name);
    const std::string &GetName();
    virtual std::string Show() = 0;
    virtual double Earnings() = 0;
};
    
#endif 
