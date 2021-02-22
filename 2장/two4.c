#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ran_max_of(const int a[], int n);

int main(void)
{
    int *height;
    int number;

    srand(time(NULL));

   
    number = 5 + rand() % 21; //사람키 랜덤 5~20 명

    height = calloc(number, sizeof(int));
    if (height == NULL)
        return 1;
    
    for (int i = 0; i < number; i++)
    {
        height[i] = 100 + rand() % 90;
        printf("%i 번째 사람의 키는 %i 입니다.\n", i + 1, height[i]);
    }

    printf("이 중 가장 큰 키는 %i 입니다.", ran_max_of(height, number));
    free(height);
}

int ran_max_of(const int a[], int n)
{
    int max = a[0];

    for (int i = 0; i < n; i++)
    {
        if (max < a[i])
            max = a[i];
    }

    return max;
}
