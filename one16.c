#include <stdio.h>

void triangleLB(int n);
void triangleLU(int n);
void triangleRU(int n);
void triangleRB(int n);

int main(void)
{
    triangleLB(4);
    printf("\n");
    triangleLU(4);
    printf("\n");
    triangleRU(4);
    printf("\n");
    triangleRB(4);
}

void triangleLB(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

void triangleLU(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= (n - i); j++)
        {
            printf("#");
        }

        printf("\n");
    }
}

void triangleRU(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int b = 1; b <= i; b++)
        {
            printf(" ");
        }

        for (int j = 1; j <= (n - i); j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
void triangleRB(int n)
{
    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= (n - i); j++)
        {
            printf(" ");
        }
        for (int b = 1; b <= i; b++)
        {
            printf("#");
        }
        printf("\n");
    }
}
