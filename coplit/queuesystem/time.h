#pragma once
#include<iostream>
using namespace std;

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

    Time& operator=(const Time& time)
    {
        m_hour = time.m_hour;
        m_minu = time.m_minu;
        m_secn = time.m_secn;
        return *this;
    }

    Time operator+(uint32_t x) const
    {
        Time result = *this;
        result.m_minu += x;
        return result;
    }



    bool operator<=(const Time& time) const
    {
        uint32_t last1 = m_hour * 3600 + m_minu * 60 + m_secn;
        uint32_t last2 = time.m_hour * 3600 + time.m_minu * 60 + time.m_secn;
        return last1 <= last2;
    }

    bool operator>=(const Time& time) const
    {
        uint32_t last1 = m_hour * 3600 + m_minu * 60 + m_secn;
        uint32_t last2 = time.m_hour * 3600 + time.m_minu * 60 + time.m_secn;
        return last1 >= last2;
    }

    bool operator<(const Time& time) const
    {
        uint32_t last1 = m_hour * 3600 + m_minu * 60 + m_secn;
        uint32_t last2 = time.m_hour * 3600 + time.m_minu * 60 + time.m_secn;
        return last1 < last2;
    }

    bool operator>(const Time& time) const
    {
        uint32_t last1 = m_hour * (uint32_t)3600 + m_minu * (uint32_t)60 + m_secn;
        uint32_t last2 = time.m_hour * (uint32_t)3600 + time.m_minu * (uint32_t)60 + time.m_secn;
        return last1 > last2;
    }

    void printTime() const
    {
        printf("%.2d:%.2d:%.2d", m_hour, m_minu, m_secn);
    }

} Time;

void swapTime(Time& time1, Time& time2);