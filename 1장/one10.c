#include <stdio.h>
#include <stdlib.h>


int main(void)
{
   int a, b;

   printf("a의 값 : ");
   scanf("%d", &a);

   do
   {   
       printf("a 보다 큰 값을 입력하세요\n");
       printf("b의 값 : ");
       scanf("%d", &b);
      
   } while (a >= b);

    printf("b - a 는 %d 입니다.\n", b-a);

   
}

