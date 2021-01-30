#include <stdio.h>
#include <stdlib.h>

void ary_reverse(int a[], int n);
void print_stat(int a[], int n);

int main(void)
{
    int *x;
    int number;

    printf("요소 개수: ");
    scanf("%i", &number); //사람 수를 받아 number에 대입한다.

    x = calloc(number, sizeof(int));
    if (x == NULL)
        return 1;

    printf("%i 개의 정수를 입력하세요\n", number);
    for (int i = 0; i < number; i++)
    {
        scanf("%i", (x + i));
    }

    ary_reverse(x, number);
    free(x);
}

void ary_reverse(int a[], int n)
{
    for (int i = 0, t = 0; i < n/2; i++)
    {
        print_stat(a, n);
        printf("a[%i]와 a[%i]를 교환합니다.\n", i, n - 1 - i);
        t = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = t;
    }
    print_stat(a, n);
    printf("역순 정렬을 종료합니다.\n");
    
}

void print_stat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", a[i]);
    }
    printf("\n");
}