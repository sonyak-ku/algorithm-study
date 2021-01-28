#include <stdio.h>
#include <stdlib.h>

int sumof(int a, int b);

int main(void)
{
    printf("숫자 %d 와 %d 사이의 값을 다 더하면 %d 입니다.", 8, 3, sumof(8, 3));
}

int sumof(int a, int b)
{
    int sum;

    int diff = abs(a-b) + 1;

    sum = ((a + b)*diff)/2;

    return sum;
}