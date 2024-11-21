#include <iostream>

int main()
{
    int j = 0;
    for (int i = 0; i < 10; i++)
    {
        j = (j++);
    }
    std::cout << j << std::endl;

    system("pause");
}