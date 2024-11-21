#include <iostream>

int &GetValue()
{
    static int value = 10;
    return value;
}

void PrintName(const std::string &name)
{
    std::cout << "[LValue]" << name << std::endl;
}
void PrintName(std::string &&name)
{
    std::cout << "[RValue]" << name << std::endl;
}
int main()
{
    int i = GetValue();
    GetValue() = 5;

    // PrintNumber(10);

    std::string firstName = "Yan";
    std::string lastName = "Cherno";

    std::string fullName = firstName + lastName;
    PrintName(fullName);
    PrintName(firstName + lastName);

    // PrintName("hello");
    system("pause");
}