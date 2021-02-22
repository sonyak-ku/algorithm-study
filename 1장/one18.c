#include <stdio.h>

void nrpira(int n);

int main(void)
{
    nrpira(5);
}

void nrpira(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int b = 1; b <= i; b++)
        {
            printf(" ");
        }

        for (int j = 1; j <= 2*n-2*i-1; j++)
        {
            printf("%d", i+1);
        }

        for (int b = 1; b <= i; b++)
        {
            printf(" ");
        }

        printf("\n");
    }
}