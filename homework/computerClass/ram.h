#include <iostream>
using namespace std;

class RAM
{
public:
    RAM();
    RAM(const RAM &ram);
    ~RAM();
    void Run();
    void Stop();
};