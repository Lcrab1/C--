#include <iostream>
#include <memory>

int main()
{
    // 创建一个unique_ptr管理一个整数
    int x = 10;
    std::unique_ptr<int> ptr1 = std::make_unique<int>(x);
    std::cout << "ptr1: " << *ptr1 << std::endl;

    // 使用std::move将所有权转移给另一个unique_ptr
    std::unique_ptr<int> ptr2 = std::make_unique<int>(x);

    // 此时ptr1不再拥有该对象
    if (!ptr1)
    {
        std::cout << "ptr1 is null after move" << std::endl;
    }

    // ptr2现在拥有该对象
    std::cout << "ptr2: " << *ptr2 << std::endl;

    system("pause");
}