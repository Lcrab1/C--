#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <ctime>
#include <limits.h>

uint32_t __mark = 0;

typedef struct Time
{
    uint32_t m_hour;
    uint32_t m_minu;
    uint32_t m_secn;
    Time()
    {
        m_hour = 8;
        m_minu = 0;
        m_secn = 0;
    }

    Time &operator=(const Time &time)
    {
        m_hour = time.m_hour;
        m_minu = time.m_minu;
        m_secn = time.m_secn;
        return *this;
    }

    Time operator+(int x) const
    {
        Time result = *this;
        result.m_minu += x;
        return result;
    }

    bool operator<=(const Time &time) const
    {
        uint32_t last1 = m_hour * 3600 + m_minu * 60 + m_secn;
        uint32_t last2 = time.m_hour * 3600 + time.m_minu * 60 + time.m_secn;
        return last1 <= last2;
    }

    bool operator<(const Time &time) const
    {
        uint32_t last1 = m_hour * 3600 + m_minu * 60 + m_secn;
        uint32_t last2 = time.m_hour * 3600 + time.m_minu * 60 + time.m_secn;
        return last1 < last2;
    }

    bool operator>(const Time &time) const
    {
        uint32_t last1 = m_hour * 3600 + m_minu * 60 + m_secn;
        uint32_t last2 = time.m_hour * 3600 + time.m_minu * 60 + time.m_secn;
        return last1 > last2;
    }

    void printTime() const
    {
        printf("%.2d:%.2d:%.2d", m_hour, m_minu, m_secn);
    }

} Time;

typedef struct _CUSTOMER_
{
    uint32_t m_num;
    uint32_t m_NoC;
    Time m_enter;
    Time m_paying;
    Time m_leave;

    _CUSTOMER_()
    {
        m_num = 0;
    }

} * Customer;

void swapTime(Time &time1, Time &time2)
{
    if (time1.m_hour != time2.m_hour)
    {
        time1.m_hour ^= time2.m_hour;
        time2.m_hour ^= time1.m_hour;
        time1.m_hour ^= time2.m_hour;
    }
    if (time1.m_minu != time2.m_minu)
    {
        time1.m_minu ^= time2.m_minu;
        time2.m_minu ^= time1.m_minu;
        time1.m_minu ^= time2.m_minu;
    }
    if (time1.m_secn != time2.m_secn)
    {
        time1.m_secn ^= time2.m_secn;
        time2.m_secn ^= time1.m_secn;
        time1.m_secn ^= time2.m_secn;
    }
}

void printEnterCus(Customer cus)
{
    cus->m_enter.printTime();
    cout << "          ";
    printf("%d", cus->m_num);
}

void printLeaveCus(Customer cus)
{
    cus->m_leave.printTime();
    cout << "          ";
    printf("%d   出队", cus->m_num);
}

uint32_t getShortest(vector<queue<Customer>> *cashier)
{
    uint32_t shortestSign = 0;
    uint32_t shortestQ = UINT32_MAX;
    for (int i = 0; i < (*cashier).size(); i++)
    {
        if ((*cashier)[i].size() < shortestQ)
        {
            shortestQ = (*cashier)[i].size();
            shortestSign = i;
        }
    }
    //记录最小队列的编号
    vector<int> help;
    int count = 0;
    for (int i = 0; i < (*cashier).size(); i++)
    {
        if ((*cashier)[i].size() == shortestQ)
        {
            help.push_back(i);
            count++;
        }
    }

    //最小队列不止一个 比较队头的paying时间，进入paying早的队列
    if (count > 1)
    {
        int earlist = 0;
        for (int i = 0; i < count - 1; i++)
        {
            //获取队列头部付款区最早的下标
            if ((*cashier)[help[i]].empty())
            {
                earlist = help[i];
                break;
            }
            Time time1 = (*cashier)[help[i]].front()->m_paying;
            Time time2 = (*cashier)[help[i + 1]].front()->m_paying;
            if (time1 <= time2)
            {
                earlist = help[i];
            }
        }
        return earlist;
    }
    return shortestSign;
}

void chooseCashier(vector<queue<Customer>> *cashier, queue<Customer> *q, Customer cus, Time &time)
{
    //决策
    //
    // 1、选择队列最短的收银台
    uint32_t shortestQ = getShortest(cashier);
    // 2、收银台为空  直接进入 直接付款
    if ((*cashier)[shortestQ].empty())
    {

        cus->m_paying = cus->m_enter;
        cus->m_leave.m_hour = cus->m_paying.m_hour;
        cus->m_leave.m_minu = cus->m_paying.m_minu + 3;
        cus->m_leave.m_secn = cus->m_paying.m_secn;
        cus->m_NoC = shortestQ;
        (*cashier)[shortestQ].push(cus);
        q->push(cus);
    }
    else
    { // 3、收银台不为空，直接进入
        (*cashier)[shortestQ].push(cus);
    }
}

//顾客进入收银台
void enterCashier(vector<queue<Customer>> *cashier, queue<Customer> *q, Time &time)
{

    Customer arr[2];

    for (int i = 0; i < 2; i++)
    {
        Customer cus = new _CUSTOMER_;
        cus->m_num = ++__mark;
        cus->m_enter.m_hour = time.m_hour;
        cus->m_enter.m_minu = time.m_minu;
        cus->m_enter.m_secn = time.m_secn + rand() % 59 + 1;
        arr[i] = cus;
        //决策并进入收银台
        chooseCashier(cashier, q, cus, time);
    }
    //进入的秒改为升序，同时修改离开的秒
    if (arr[0]->m_enter > arr[1]->m_enter)
    {
        swapTime(arr[0]->m_enter, arr[1]->m_enter);
        swapTime(arr[0]->m_leave, arr[1]->m_leave);
    }

    //打印顾客进入收银台的信息  同时会有顾客离开收银台
    while (!q->empty() && q->front()->m_leave < arr[0]->m_enter)
    {
        Customer temp = q->front();
        q->pop();
        (*cashier)[temp->m_NoC].pop();
        if (!(*cashier)[temp->m_NoC].empty())
        {
            q->push((*cashier)[temp->m_NoC].front());
        }
        printLeaveCus(temp);
        printf("\r\n");
        // delete temp;
    }
    while (!q->empty() && q->front()->m_leave < arr[1]->m_enter)
    {
        Customer temp = q->front();
        q->pop();
        (*cashier)[temp->m_NoC].pop();
        if (!(*cashier)[temp->m_NoC].empty())
        {
            q->push((*cashier)[temp->m_NoC].front());
        }
        printLeaveCus(temp);
        printf("\r\n");
        // delete temp;
    }
    for (int i = 0; i < 2; i++)
    {
        printEnterCus(arr[i]);
        printf("\r\n");
    }

    time.m_minu++;
}
//顾客付款，离开收银台

void test_unit1()
{
    queue<Customer> *Q = new queue<Customer>;
    vector<queue<Customer>> *Cashier = new vector<queue<Customer>>(4);
    Time time;
    for (int i = 0; i < 60; i++)
    {
        enterCashier(Cashier, Q, time);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    test_unit1();
}
