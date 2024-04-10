#include <time.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>
int main()
{

    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char buf[256];
    strftime(buf, sizeof(buf), "%c", tm);
    printf("%s\n", buf);
    system("pause");
    return 0;
}