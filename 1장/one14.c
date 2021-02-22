#include <stdio.h>

int main(void)
{
    int n;

    do
    {   
        printf("입력할 수 :");
        scanf("%d", &n);
        /* code */
    } while (n<=0);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}