#include <iostream>
using namespace std;

class CDROM
{
    public:
        CDROM();
        CDROM(const CDROM &cdrom);
        ~CDROM();
        void Run();
        void Stop();
};