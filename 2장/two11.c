#include <stdio.h>
#include <stdlib.h>

int mdays[][12];
int isleap(int year);
int dayofyear(int y, int m , int d);

int main(void)
{
    int year, month, day;
    int retry;
    do
    {
        printf("year : "); scanf("%d", &year);
        printf("month : "); scanf("%d", &month);
        printf("day : "); scanf("%d", &day);

        printf("%d년의 %d 일째입니다.\n", year, dayofyear(year, month, day));
        printf("다시 할까요?(1 ... 에/ 0 ... 아니오) : ");
        scanf("%d", &retry);
    } while (retry == 1);
}

int mdays[][12] = {
    {31,28,31,30,31,30,31,31,30,31,30,31},
    {31,29,31,30,31,30,31,31,30,31,30,31}
};

int isleap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayofyear(int y, int m , int d)
{
    
    while(m != 1)
    {
         d += mdays[isleap(y)][m - 2];
         m--;
    }

    return d;
}