#include <stdio.h>

int sum(int n);

int main(void)
{
    int a;

    printf("숫자를 입력해주세요: ");
    scanf("%d", &a);

    printf("1 부터 %d 까지의 숫자의 합은 %d 입니다.\n", a, sum(a));
}

int sum(int n)
{
    int sum = 0;

    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }

    return sum;
}