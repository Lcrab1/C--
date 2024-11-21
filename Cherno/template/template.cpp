#include <iostream>
template <typename T ,int N>
class Array
{
private:
    T m_Array[N];

public:
    int GetSize() const
    {
        return N;
    }
};

// class Array
// {
// private:
//     int m_Array[5];

// public:
//     int GetSize() const
//     {
//         return 5;
//     }
// };

int main()
{
    Array<char,5> array;
}
