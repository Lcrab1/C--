#include <iostream>
using namespace std;

typedef unsigned char *type_pointer;

char* getByte(type_pointer start, size_t len)
{
    char* byte = new char[len];
    for (size_t i = 0; i < len; i++)
    {
        byte[i] = start[i];
        printf("%.2x", start[i]);
    }
    printf("\n");
    return byte;
}



bool isLittleEndian()
{
    int x = 1;
    char *c = (char *)&x;
    return *c == 1;
}

int main()
{
    bool ret = isLittleEndian();
    cout << "Is Little Endian? " << (ret ? "Yes" : "No") << endl;
    cout << "Is Big Endian? " << (ret ? "No" : "Yes") << endl;
    system("pause");
}