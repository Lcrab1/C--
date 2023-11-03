#include <iostream>
#include <tchar.h>
using namespace std;
#define MAX 5

#pragma pack(1)
typedef struct _NUM_
{
    int *Num;
    int length;
    int MaxLength;

    _NUM_()
    {
        memset(this, 0, sizeof(_NUM_));
        Num = new int[MAX];
        MaxLength = MAX;
    }

    ~_NUM_()
    {
        if (Num != nullptr)
        {
            delete Num;
            memset(this, 0, sizeof(_NUM_));
            Num = nullptr;
        }
    }

} Num;

//动态创建数组
void EnterNum(Num *num);
void AddTwoBigNumbers(Num *num1, Num *num2);

int main()
{
    printf("请输入两个数字\r\n");
    Num num1;
    EnterNum(&num1);
    Num num2;
    EnterNum(&num2);
    AddTwoBigNumbers(&num1, &num2);
    system("pause");
}

void EnterNum(Num *num)
{
    char v1;
    v1 = _gettchar();
    while (v1 != 0xA)
    {
        if (num->length + 1 == num->MaxLength)
        {
            num->MaxLength += MAX;
            int *v5 = new int[num->MaxLength];
            memcpy(v5, num->Num, sizeof(int) * num->length);
            delete num->Num;
            num->Num = v5;
        }
        num->Num[num->length] = v1 - '0';
        num->length++;
        v1 = _gettchar();
    }
    num->Num[num->length] = 0x00;
    // _tprintf(_T("%s"), num->Num);
}

void AddTwoBigNumbers(Num *num1, Num *num2)
{
    int i = 0;
    Num *big = num1->length > num2->length ? num1 : num2;
    Num *small = num1->length > num2->length ? num2 : num1;

    for (int i = 0; i < small->length; i++)
    {
        int curB = big->length - 1 - i;
        int curS = small->length - 1 - i;
        if (curS < 0)
            curS += small->length;
        if (i == big->length - 2 && big->Num[curB] + small->Num[curS] >= 10)
        {
            big->length++;
            int *v5 = new int[big->length];
            memcpy(v5 + 2, big->Num + 2, big->length * sizeof(int));
            v5[0] = 1;
            v5[1] = big->Num[curB] + small->Num[curS] % 10;
            delete big->Num;
            big->Num = v5;
            big->MaxLength++;
            break;
        }
        if (big->Num[curB] + small->Num[curS] >= 10)
        {
            big->Num[curB - 1]++;
            big->Num[curB] = (big->Num[curB] + small->Num[curS]) % 10;
        }
        else
            big->Num[curB] = big->Num[curB] + small->Num[curS];
    }
    for (int i = 0; i < big->length; i++)
        cout << big->Num[i];
    cout << endl;
}