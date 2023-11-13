#include<iostream>
using namespace std;

template <class T>
class matrix{
    friend ostream & < operator<<(ostream &, const matrix<T> &);
    public:
        matrix(int theRows = 0, int theColumn = 0);
        matrix(const matrix<T> &);
        ~matrix() { delete[] element; }
        int rows() const { return theRows; }
        int columns() const { return theColumns; }
        T &operator()(int i, int j) const;
        matrix<T> &operator=(const matrix<T> &);
        matrix<T> operator+() const;
        matrix<T> operator+(const matrix<T> &) const;
        matrix<T> operator-() const;
        matrix<T> operator-(const martirx<T> &) const;
        matrix<T> operator*(const matrix<T> &) const;
        matrix<T>& operator+=(const T &);

    private:
        int theRows;
        int theColumns;
        T *element;
};

