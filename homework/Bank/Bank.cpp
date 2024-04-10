// 第三次实验

#include <iostream>
using namespace std;

class BBank;
class ABank;

class CBank
{ //声明中国银行类
public:
    friend void total(const CBank &a, const BBank &b, const ABank &c);
    CBank() {}
    CBank(int newBalance)
    {
        balance = newBalance;
    }
    void SetBalance(int newBalance)
    {
        balance = newBalance;
    }
    void Display()
    {
        cout << "您当前在中国银行中的存款余额为：" << balance << "元" << endl;
    }

private:
    int balance;
};

class BBank
{ //声明工商银行类
public:
    friend void total(const CBank &a, const BBank &b, const ABank &c);
    BBank() {}
    BBank(int newBalance)
    {
        balance = newBalance;
    }
    void SetBalance(int newBalance)
    {
        balance = newBalance;
    }
    void Display()
    {
        cout << "您当前在工商银行中的存款余额为：" << balance << "元" << endl;
    }

private:
    int balance;
};

class ABank
{ //声明农业银行类
public:
    friend void total(const CBank &a, const BBank &b, const ABank &c);
    ABank() {}
    ABank(int newBalance)
    {
        balance = newBalance;
    }
    void SetBalance(int newBalance)
    {
        balance = newBalance;
    }
    void Display()
    {
        cout << "您当前在农业银行中的存款余额为：" << balance << "元" << endl;
    }

private:
    int balance;
};

void total(const CBank &a, const BBank &b, const ABank &c)
{
    cout << "您当前的余款总额为：" << a.balance + b.balance + c.balance << "元" << endl;
}

int main()
{
    CBank x(100);
    BBank y(200);
    ABank z(300);
    x.Display();
    y.Display();
    z.Display();
    x.SetBalance(50);
    x.Display();
    total(x, y, z);
    system("pause");
    return 0;
}
