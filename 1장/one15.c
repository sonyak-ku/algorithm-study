#include <stdio.h>

int main(void)
{
    int a, b;

    do
    {   
        printf("높이 :");
        scanf("%d", &a);
        /* code */
        printf("너비 :");
        scanf("%d", &b);
    } while (a<=0 || b<=0);

    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            printf("*");
        }
        printf("\n");
    }
    
}