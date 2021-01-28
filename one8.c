#include <stdio.h>

int gauss(int n);

int main(void)
{
    int a;

    printf("숫자를 입력해주세요: ");
    scanf("%d", &a);

    printf("1 부터 %d 까지의 숫자의 합은 %d 입니다.\n", a, gauss(a));
}

int gauss(int n)
{
    int sum = (n*(n+1))/2;
   
    return sum;
}