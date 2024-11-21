#include <iostream>
#include "boss.h"
#include "pieceworker.h"
#include "hourlyworker.h"
int main()
{
    Boss b("John", 800.0);
    PieceWorker p("Bob", 2.5, 200);
    HourlyWorker h("Karen", 13.75, 40);

    Employee *ref;

    ref = &b;
    std::cout << ref->Show() << " earned $" << ref->Earnings() << std::endl;
    std::cout << b.Show() << " earned $" << b.Earnings() << std::endl;

    ref = &p;
    std::cout << ref->Show() << " earned $" << ref->Earnings() << std::endl;
    std::cout << p.Show() << " earned $" << p.Earnings() << std::endl;

    ref = &h;
    std::cout << ref->Show() << " earned $" << ref->Earnings() << std::endl;
    std::cout << h.Show() << " earned $" << h.Earnings() << std::endl;

    system("pause");
    return 0;
}
