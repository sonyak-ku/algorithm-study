#include <stdio.h>

void spira(int n);

int main(void)
{
    spira(6);
}

void spira(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int b = 1; b<= (n-i); b++)
        {
            printf(" ");
        }

        for (int j = 1; j <= (2*i-1); j++)
        {
            printf("*");
        }

        for (int b = 1; b<= (n-i); b++)
        {
            printf(" ");
        }

        printf("\n");
    }
}