#include <iostream>
using namespace std;

int main()

{
    char encode[10] = {"~Znw:y5v|"};
    char decode[10] = {0};
    for (int i = 0; i < 10; i++)
    {
        decode[i] = (encode[i] - 9 + i) ^ i;
    }

    for (int i = 0; i < 10;i++){
        cout << decode[i];
    }

    system("pause");
}