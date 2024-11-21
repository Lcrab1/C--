#include "pieceworker.h"

PieceWorker::PieceWorker(std::string name, double wagePerPiece, unsigned int quantity)
    : Employee(name), wagePerPiece(wagePerPiece), quantity(quantity)
{
}
void PieceWorker::SetWagePerPiece(double wagePerPiecee)
{
    wagePerPiece = wagePerPiece;
}
void PieceWorker::SetQuantity(unsigned int quantity)
{
    quantity = quantity;
}
std::string PieceWorker::Show()
{
    return std::string("PieceWorker ") += GetName();
}
double PieceWorker::Earnings()
{
    return quantity * wagePerPiece;
}