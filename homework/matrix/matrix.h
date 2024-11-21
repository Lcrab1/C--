#include <iostream>
#include <ctime>
class Matrix
{
private:
    //最大值
    int m_Max;
    int m_RowOfMax;
    int m_ColumnOfMax;
    //最小值
    int m_Min;
    int m_RowOfMin;
    int m_ColumnOfMin;

    int m_Row;
    int m_Column;
    int *m_Content;

public:
    Matrix(int row, int column);
    ~Matrix();
    //显示矩阵
    void ShowMatrix();
    //行列互换
    void MartirxTransformation();
    void GetExtremeValue();
};