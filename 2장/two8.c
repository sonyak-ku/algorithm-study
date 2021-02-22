#include <stdio.h>
#include <stdlib.h>

void ary_copy(int a[], const int b[], int n);
int main(void)
{
    int *ary;
    int *copy;
    int number;

    printf("요소의 갯수: ");
    scanf("%i", &number); //사람 수를 받아 number에 대입한다.

    ary = calloc(number, sizeof(int));
    copy = calloc(number, sizeof(int));
    
    if (ary == NULL)
        return 1;

    printf("%i 개의 숫자를 입력하세요\n", number);
    for (int i = 0; i < number; i++)
    {
        printf("%i 번째 숫자: ", i + 1);
        scanf("%i", (ary + i));
    }

    ary_copy(copy, ary, number);

    for (int i = 0; i < number; i++)
    {
        printf("원래 배열과 복사된 배열의 %d번째 요소는 각각 %d 와 %d 입니다.\n", i ,ary[i], copy[i]);
    }

    free(ary);
    free(copy);
    
}

void ary_copy(int a[], const int b[], int n)
{
    
    for(int i = 0; i < n; i++)
    {
        a[i] = b[i];
    }
}
