#include <iostream>
#include <array>

// c语言的函数指针
void HelloWorld()
{
    std::cout << "HelloWorld" << std::endl;
}

void ForEach(const std::array<int, 5> &values, void (*func)(int x))
{
    for (int value : values)
    {
        func(value);
    }
}

void Print(int x)
{
    std::cout << x << std::endl;
}

int main()
{
    // 1.使用auto关键字来接收函数指针
    //  auto func = HelloWorld;
    //  func();

    // 2.使用c语言的原始函数指针
    //  void (*function)();
    //  function = HelloWorld;
    //  function();

    // 3.使用typedef来定义函数指针数据类型
    //  typedef void (*function)();
    //  function HelloWorldFunction = HelloWorld;
    //  HelloWorldFunction();

    // 4.函数指针作接口调用
    // const std::array<int, 5> values = {5, 4, 3, 2, 1};
    // typedef void (*PRINT)(int x);
    // PRINT func = Print;
    // ForEach(values, func);

    // 5.引入lambda表达式
    const std::array<int, 5> values = {5, 4, 3, 2, 1};
    ForEach(values, [](int x)
            { std::cout << x << std::endl; });

    system("pause");
}