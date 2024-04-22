#include <iostream>
class Entity
{
private:
    Entity()
        : m_Value(10)
    {
    }

private:
    int m_Value;

public:
    static Entity m_Entity;

public:
    int GetValue()
    {
        return m_Value;
    }
};

Entity Entity::m_Entity;
