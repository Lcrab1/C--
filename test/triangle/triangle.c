#include <stdio.h>
int IsTriangle(float a, float b, float c)
{
    return a + b > c && a + c > b && b + c > a;
}

int main()
{
    printf("请输入三角形的三条边长（以空格分隔）\r\n");
    for (int i = 0; i < 10; i++)
    {
        float a = 0, b = 0, c = 0;
        scanf("%f %f %f", &a, &b, &c);
        if (IsTriangle(a, b, c))
        {
            printf("Y\r\n");
        }
        else
        {
            printf("N\r\n");
        }
    }
}