#include "class.h"

void ChangeValue()
{
    Test t;
    t.m_Value = 10;
}

Test::Test()
{
}
Test::~Test()
{
}

int Test::m_Value = 20;