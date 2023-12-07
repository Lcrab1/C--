#pragma once
#include<iostream>
#include"time.h"
using namespace std;

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

} *Customer;