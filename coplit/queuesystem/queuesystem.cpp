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
    cout << setw(6) << "时间" << setw(18) << "顾客编号" << setw(14) << "状态" << setw(16) << "收银台编号" << setw(20) << "收银台人数" << setw(18) << "等待时间" << endl;
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
