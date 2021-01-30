#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int a[], int n);

int main(void)
{
   int *ary;
   int number;

   srand(time(NULL));

   printf("요소의 갯수: ");
   scanf("%i", &number); //사람 수를 받아 number에 대입한다.
   ary = calloc(number, sizeof(int));

   if (ary == NULL)
        return 1;

    printf("%i 개의 숫자를 입력하세요\n", number);
    for (int i = 0; i < number; i++)
    {
        printf("%i 번째 숫자: ", i + 1);
        scanf("%i", (ary + i));
    }           // 배열 a  개수 정하고, 숫자 넣는 것.


 
    
}

void shuffle(int a[], int n)
{
    
    srand(time(NULL));
    int b,c;

    b = rand() %n;
    c = rand() %n;

    int tmp =0;
    tmp = a[b];
    a[b] = a[c];
    a[c] = tmp;

}
