#include <stdio.h>

int main(void)
{
    printf("  |");
    for (int i = 1; i <= 9; i++)
    {
        printf("%d  ", i);
    }

    printf("\n");
    for (int i = 1; i <= 9; i++)
    {
        printf("---");
    }
    
    printf("\n");
    for (int i = 1; i <= 9; i++)
    {

        printf("%d |", i);

        for (int j = 1; j <= 9; j++)
        {   
            
            printf("%d ", j*i);
        }

        printf("\n");
    }
}