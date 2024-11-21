#include "matrix.h"

Matrix::Matrix(int row, int column)
    : m_Max(0), m_RowOfMax(0), m_ColumnOfMax(0), m_Min(INT_MAX), m_RowOfMin(0), m_ColumnOfMin(0),
      m_Row(row), m_Column(column), m_Content(new int[row * column])
{
    //������ֵ
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
//��ʾ����
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
    std::cout << "�����е����ֵΪ:" << m_Max << "��������Ϊ:" << m_RowOfMax + 1 << "��������Ϊ:" << m_ColumnOfMax + 1 << std::endl;
    std::cout << "�����е���СֵΪ:" << m_Min << "��������Ϊ:" << m_RowOfMin + 1 << "��������Ϊ:" << m_ColumnOfMin + 1 << std::endl;
}
//���л���
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
    //����������е������Сֵ
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