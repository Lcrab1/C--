#include <iostream>
#include <Windows.h>
using namespace std;

int getNewArr13(__int64 *dest, __int64 numberIs16, DWORD *arr13);

int main()
{
    char arr13[368];
    char userName[17] = {"user01_nkctf2024"};
    __int64 dest[4];
    memset(dest, 0, sizeof(dest));
    memcpy(dest, userName, 16);
    getNewArr13(dest, 16, (DWORD *)arr13);
    system("pause");
}

int getNewArr13(__int64 *dest, __int64 numberIs16, DWORD *arr13)
{
    for (int i = 0; i <= 3; ++i)
        arr13[i] = (*(unsigned __int8 *)(4 * i + 2LL + dest) << 8) | (*(unsigned __int8 *)(4 * i + 1LL + dest) << 16) | (*(unsigned __int8 *)(4 * i + dest) << 24) | *(unsigned __int8 *)(4 * i + 3LL + dest);
    for (int i = 0; i < 4; i++)
    {
        cout << arr13[i] << " ";
    }
    return 0;
}