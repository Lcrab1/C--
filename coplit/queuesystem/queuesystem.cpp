#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <ctime>
#include <iomanip>
#include "customer.h"
#include "time.h"
#include "cashier.h"

void eightToNine()
{
    queue<Customer> *Q = new queue<Customer>;
    vector<queue<Customer>> *Cashier = new vector<queue<Customer>>(6);
    Time time;
    cout << setw(6) << "ʱ��" << setw(18) << "�˿ͱ��" << setw(14) << "״̬" << setw(16) << "����̨���" << setw(20) << "����̨����" << setw(18) << "�ȴ�ʱ��" << endl;
    for (int i = 0; i < 60; i++)
    {
        enterCashier(Cashier, Q, time);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    eightToNine();
    system("pause");
}
