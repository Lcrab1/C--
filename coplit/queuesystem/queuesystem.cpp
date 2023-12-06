#include <iostream>
#include <ctime>
#include <queue>
#include <vector>
using namespace std;

typedef struct _TIME_
{
    uint32_t hour;
    uint32_t mins;
    uint32_t sec;

    _TIME_()
    {
        hour = 8;
        mins = 0;
        sec = 0;
    }

    void printTime()
    {
        printf("%.2d:%.2d:%.2d", hour, mins, sec);
    }

} TIME;

typedef struct _CUSTOMER_
{
    TIME enter;  //进入队列的时刻
    TIME paying; //付款的时刻
    TIME leave;  //离开的时刻
    int num;     //顾客编号
    int NoC;     // Number of Cashier
    bool flag = false;
} CUS;

int __NoC = 0;  //顾客编号    number of customer
queue<CUS> __Q; //四个收银台队首 再成一个队列

//四个销售台用vector存储
vector<queue<CUS>> __Cashier(4); // manage Cashier

int getShortest()
{
    int smallest = 0;
    for (int i = 0; i < 4 - 1; i++)
    {
        smallest = __Cashier[i].size() < __Cashier[i + 1].size() ? i : i + 1;
    }
    return smallest;
}

void timeUpdata(TIME* time)
{
    TIME pretime;
    //只记录当前小时和分钟，秒数随机生成
    pretime.hour = time->hour;
    pretime.mins = time->mins;
    pretime.sec = 0;
    // custumer.time.sec=
    pretime.sec += rand() % 59 + 1;
    time->sec = pretime.sec;
    //用不到
    if (time->sec >= 60)
    {
        time->mins++;
        time->sec -= 60;
    }
    if (time->mins >= 60)
    {
        time->hour++;
        time->mins -= 60;
    }
}

//每分钟更新两次，对应两个顾客
void updataPerMinute(TIME* time, CUS* cus)
{ //可以同时传入顾客
    TIME updataTime[2];
    for (int i = 0; i < 2; i++)
    {
        timeUpdata(time);
        //同时更新顾客的enter时间
        cus[__NoC].enter = *time;
        //更新顾客的编号
        cus[__NoC].num = __NoC + 1;

        updataTime[i] = *time;

        //得到队列最短的收银台编号
        int sig = getShortest();
        //新顾客进入队列最短的队伍
        if (__Cashier[sig].size() == 0)
        {
            __Cashier[sig].push(cus[__NoC]);
            cus[__NoC].NoC = sig;
            //柜台人数均为0时,即初始状态
            cus[__NoC].paying = cus[__NoC].enter;
            cus[__NoC].leave = cus[__NoC].paying;
            cus[__NoC].leave.mins += 3;

            cus[__NoC].flag = true;

            //__Q.push(cus[__NoC]);
        }
        else
        {
            cus[__NoC].NoC = sig;
            __Cashier[sig].push(cus[__NoC]);
        }
        __NoC++;
    }
    //按照sec进行升序
    if (cus[__NoC - 2].paying.sec < cus[__NoC - 1].paying.sec)
    {
        cus[__NoC - 2].paying.sec ^= cus[__NoC - 1].paying.sec;
        cus[__NoC - 1].paying.sec ^= cus[__NoC - 2].paying.sec;
        cus[__NoC - 2].paying.sec ^= cus[__NoC - 1].paying.sec;
        if (cus[__NoC - 2].flag == true) {
            __Q.push(cus[__NoC - 2]);
        }
        if (cus[__NoC - 1].flag == true)
        {
            __Q.push(cus[__NoC - 1]);
        }
    }
    else if (cus[__NoC - 2].flag == true)
    {
        __Q.push(cus[__NoC - 2]);
    }
    else if (cus[__NoC - 1].flag == true) {
        __Q.push(cus[__NoC - 1]);
    }

    //按照time->sec进行升序
    if (updataTime[0].sec > updataTime[1].sec)
    {
        updataTime[0].sec ^= updataTime[1].sec;
        updataTime[1].sec ^= updataTime[0].sec;
        updataTime[0].sec ^= updataTime[1].sec;
    }
    for (int i = 0; i < 2; i++)
    {
        //打印新顾客的入队时间前判断是否有顾客可以出队
        if (!__Q.empty())
        {
            CUS curPayingCus = __Q.front();
            if (updataTime[i].mins > curPayingCus.leave.mins || updataTime[i].mins == curPayingCus.leave.mins && updataTime[i].sec > curPayingCus.leave.sec)
            {
                //输出顾客的信息
                cout << "顾客离开时间:";
                curPayingCus.leave.printTime();
                printf("\r\n");
                //弹出队头
                __Q.pop();
                //从收银台弹出
                __Cashier[curPayingCus.NoC].pop();
                //新进入收银台顾客的收银时间是队头顾客的离开时间
                if (!__Cashier[curPayingCus.NoC].empty())
                {
                    CUS* temp = &__Cashier[curPayingCus.NoC].front();
                    temp->paying = curPayingCus.leave;
                    temp->leave.mins = temp->paying.mins + 3;
                    temp->leave.sec = curPayingCus.leave.sec;
                    __Q.push(*temp);
                }
            }
        }


        updataTime[i].printTime();
        printf("\r\n"); //可在此处输出其他数据
    }
    time->mins++;
}

void timeTable(TIME* time, CUS* cus)
{
    uint32_t simulTimes = 60; //经过分钟数
    for (int i = 0; i < simulTimes; i++)
    {
        updataPerMinute(time, cus);
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    TIME* time = new TIME;
    CUS* cus = new CUS[120];
    timeTable(time, cus);
    system("pause");
}