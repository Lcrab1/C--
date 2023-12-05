#include <iostream>
#include <vector>
#include <random>
#include <queue>
using namespace std;
const int Total_Time = 60;      //总时间
const int Arrival_Rate = 2;     //顾客到来速率
const int Checkout_Time = 3;    //每个顾客的收银时间
const int Max_Queue_Length = 4; //队列长度限制
int main()
{
    int Min_Queue_Length = INT_MAX;
    int Current_NumOf_Cashiers = 1;
    int Current_Queue_Length = 0;
    int NumOf_Cashiers = 1;
    vector<queue<int>> cashiers(100); //创建收银台
    cout << "时间（min）"<< "    "<< "1号"<< "    "<< "2号"<< "    "<< "3号"<< "    "<< "4号"<< "    "<< "5号" << "    " << "6号" << "    " << "7号" << endl;
    for (int Current_Time = 1; Current_Time <= Total_Time; Current_Time++) //模拟顾客到来的过程
    {
        int Num_Arrivals = 2; //这里可以直接改成 "2"
        for (int i = 0; i < Num_Arrivals; i++)
        {
            int Shortest_Queue = 0;
            int Min_Queue_Length = cashiers[0].size();
            for (int j = 1; j < NumOf_Cashiers; j++)
            {
                if (cashiers[j].size() < Min_Queue_Length)
                {
                    Shortest_Queue = j;
                    Min_Queue_Length = cashiers[j].size();
                }
            }
            // cashiers[Shortest_Queue].push(Current_Time);
            if (!cashiers[Shortest_Queue].empty())
            {
                cashiers[Shortest_Queue].push(Current_Time + cashiers[Shortest_Queue].size() * 3);
            }
            else
            {
                cashiers[Shortest_Queue].push(Current_Time);
            }
        }
        int count = 0;
        for (int i = 0; i < NumOf_Cashiers; i++) //处理每个收银台的顾客
        {
            if (!cashiers[i].empty())
            {
                if (Current_Time - cashiers[i].front() >= Checkout_Time)
                {
                    cashiers[i].pop();
                    count++;
                }
            }
        }
        Current_Queue_Length = Current_Queue_Length + 2 - count;
        if ((Current_Queue_Length / NumOf_Cashiers >= Max_Queue_Length) && (NumOf_Cashiers == 1))
        {
            NumOf_Cashiers++;
        }
        if ((Current_Queue_Length / NumOf_Cashiers >= Max_Queue_Length) && (Current_Queue_Length / NumOf_Cashiers != 0) && (NumOf_Cashiers != 1)) //检查队列长度是否超出限制
        {
            NumOf_Cashiers++;
        }
        if (Current_Time < 10)
        {
            cout << Current_Time << "              " << cashiers[0].size() << "      " << cashiers[1].size() << "      " << cashiers[2].size() << "      " << cashiers[3].size() << "      " << cashiers[4].size() << "      " << cashiers[5].size() << "      " << cashiers[6].size() << endl;
        }
        else
        {
            cout << Current_Time << "             " << cashiers[0].size() << "      " << cashiers[1].size() << "      " << cashiers[2].size() << "      " << cashiers[3].size() << "      " << cashiers[4].size() << "      " << cashiers[5].size() << "      " << cashiers[6].size() << endl;
        }
    }
    if (Current_Queue_Length < Min_Queue_Length)
    {
        Min_Queue_Length = Current_Queue_Length;
        Current_NumOf_Cashiers = NumOf_Cashiers;
    }
    printf("同时开设收银台的数目为：%d", Current_NumOf_Cashiers);
    system("pause");
    return 0;
}