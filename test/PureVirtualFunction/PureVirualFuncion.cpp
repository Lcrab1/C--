#include <iostream>

class CManager
{
public:
    virtual void HandleIO() = 0;

private:
};

class KernelManager : public CManager
{
public:
    void HandleIO() override
    {
        std::cout << "HandleIO in KernelManager" << std::endl;
    }
};

class MemoryManager : public CManager
{
public:
    void HandleIO() override
    {
        std::cout << "HandleIO in MemoryManager" << std::endl;
    }
};

void HandleIO(CManager *obj)
{
    obj->HandleIO();
}

int main()
{
    CManager *kernerManager = new KernelManager;
    CManager *memoryManager = new MemoryManager;
    HandleIO(kernerManager); // Call the HandIO function to invoke the HandleIO function on the CManager object
    HandleIO(memoryManager);
    delete kernerManager; // Deallocate the memory allocated for the KernelManager object
    delete memoryManager;
    system("pause");
    return 0;
}