#include"employee.h"
class Boss : public Employee
{
    private:
        double weeklySalary;
    public:
        Boss(const std::string &name, const double weeklySalary);
        void SetWeeklySalary(double salary);
        std::string Show() override;
        double Earnings() override;
};