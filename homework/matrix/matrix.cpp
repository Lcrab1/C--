#include "matrix.h"

Matrix::Matrix(int row, int column)
    : m_Max(0), m_RowOfMax(0), m_ColumnOfMax(0), m_Min(INT_MAX), m_RowOfMin(0), m_ColumnOfMin(0),
      m_Row(row), m_Column(column), m_Content(new int[row * column])
{
    //给矩阵赋值
    srand(time(0));
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            m_Content[column * i + j] = 10 + rand() % 90;
        }
    }
}

Matrix::~Matrix()
{
    if (m_Content != nullptr)
    {
        delete m_Content;
        m_Content = nullptr;
    }
}
//显示矩阵
void Matrix::ShowMatrix()
{
    for (int i = 0; i < m_Row; i++)
    {
        for (int j = 0; j < m_Column; j++)
        {
            std::cout << m_Content[m_Column * i + j] << "  ";
        }
        std::cout << std::endl;
    }
    GetExtremeValue();
    std::cout << "矩阵中的最大值为:" << m_Max << "，所在行为:" << m_RowOfMax + 1 << "，所在列为:" << m_ColumnOfMax + 1 << std::endl;
    std::cout << "矩阵中的最小值为:" << m_Min << "，所在行为:" << m_RowOfMin + 1 << "，所在列为:" << m_ColumnOfMin + 1 << std::endl;
}
//行列互换
void Matrix::MartirxTransformation()
{
    int *oldMatrix = m_Content;
    int *newMatrix = new int[m_Row * m_Column];
    m_Content = newMatrix;
    for (int i = 0; i < m_Row; i++)
    {
        for (int j = 0; j < m_Column; j++)
        {
            newMatrix[4 * i + j] = oldMatrix[4 * j + i];
        }
    }

    delete oldMatrix;
    oldMatrix = nullptr;
}

void Matrix::GetExtremeValue()
{
    //计算出矩阵中的最大最小值
    for (int i = 0; i < m_Row; i++)
    {
        for (int j = 0; j < m_Column; j++)
        {
            if (m_Max <= m_Content[m_Column * i + j])
            {
                m_Max = m_Content[m_Column * i + j];
                m_RowOfMax = i;
                m_ColumnOfMax = j;
            }
            if (m_Min >= m_Content[m_Column * i + j])
            {
                m_Min = m_Content[m_Column * i + j];
                m_RowOfMin = i;
                m_ColumnOfMin = j;
            }
        }
    }
}