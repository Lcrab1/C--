// ������ʵ��

#include <iostream>
using namespace std;

class BBank;
class ABank;

class CBank
{ //�����й�������
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
        cout << "����ǰ���й������еĴ�����Ϊ��" << balance << "Ԫ" << endl;
    }

private:
    int balance;
};

class BBank
{ //��������������
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
        cout << "����ǰ�ڹ��������еĴ�����Ϊ��" << balance << "Ԫ" << endl;
    }

private:
    int balance;
};

class ABank
{ //����ũҵ������
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
        cout << "����ǰ��ũҵ�����еĴ�����Ϊ��" << balance << "Ԫ" << endl;
    }

private:
    int balance;
};

void total(const CBank &a, const BBank &b, const ABank &c)
{
    cout << "����ǰ������ܶ�Ϊ��" << a.balance + b.balance + c.balance << "Ԫ" << endl;
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
