#include <stdio.h>
#include <stdlib.h>

int minof(const int a[], int n);

int main(void)
{
    int *height;
    int number;

    printf("사람 수: ");
    scanf("%i", &number); //사람 수를 받아 number에 대입한다.

    height = calloc(number, sizeof(int));
    if (height == NULL)
        return 1;

    printf("%i 사람의 키를 입력하세요\n", number);
    for (int i = 0; i < number; i++)
    {
        printf("%i 번째 사람의 키: ", i + 1);
        scanf("%i", (height + i));
    }

    printf("이 중 가장 작은 키는 %i 입니다.", minof(height, number));
    free(height);
}

int minof(const int a[], int n)
{
    int min = a[0];

    for (int i = 0; i < n; i++)
    {
        if (min > a[i])
            min = a[i];
    }

    return min;
}
