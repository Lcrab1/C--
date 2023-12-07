#include"print.h"
void printEnterCus(Customer cus, vector<queue<Customer>>* cashier)
{
    cout << setw(6);
    cus->m_enter.printTime();
    cout << setw(12) << cus->m_num << setw(18) << "入队" << setw(12) << cus->m_NoC +1<< setw(20) << (*cashier)[cus->m_NoC].size() << setw(18)
        << 0 << endl;
}

void printLeaveCus(Customer cus, vector<queue<Customer>>* cashier)
{
    cout << setw(6);
    cus->m_leave.printTime();
    uint32_t Waiting = (cus->m_leave.m_minu * 60 + cus->m_leave.m_secn) - (cus->m_enter.m_minu * 60 + cus->m_enter.m_secn);
    uint32_t WaitingM = Waiting / 60;
    uint32_t WaitingS = Waiting % 60;

    cout << setw(12) << cus->m_num << setw(18) << "出队" << setw(12) << cus->m_NoC+1 << setw(20) << (*cashier)[cus->m_NoC].size() << setw(16)
        << WaitingM << "分" << WaitingS << "秒" << endl;
}