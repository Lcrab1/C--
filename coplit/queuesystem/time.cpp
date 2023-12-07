#include"time.h"

void swapTime(Time& time1, Time& time2)
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