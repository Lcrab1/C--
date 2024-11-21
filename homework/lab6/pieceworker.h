#include "employee.h"
class PieceWorker:public Employee
{
private:
    double wagePerPiece;
    unsigned int quantity;

public:
    PieceWorker(std::string name,double wagePerPiece,unsigned int quantity);
    void SetWagePerPiece(double wagePerPiecee);
    void SetQuantity(unsigned int quantity);
    std::string Show() override;
    double Earnings() override;
};