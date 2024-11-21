#include <iostream>
#include <string>

class Entity
{
public:
    void Print() const
    {
        std::cout << "Hello!" << std::endl;
    }
};

class ScopePtr
{
private:
    Entity *m_Obj;

public:
    ScopePtr()

    {
    }
    ScopePtr(Entity *entity)
        : m_Obj(entity)
    {
    }
    ~ScopePtr()
    {
        delete m_Obj;
    }
    Entity *operator->()
    {
        return m_Obj;
    }
};

//获取结构体中内存偏移
struct Vector3{
    float x, y, z;
};

int main()
{
    // Entity *e;
    // e->Print();

    ScopePtr entity = new Entity();
    entity->Print();
    //gcc编译会提示有精度损失  vs没有问题
    uintptr_t offset = reinterpret_cast<uintptr_t>(&((Vector3 *)nullptr)->x);
    std::cout << offset << std::endl;
    std::cin.get();
}