#include <stdio.h>

typedef struct
{
    int y;
    int m;
    int d;
} Date;

int mdays[][12] = {
    {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};

int isleap(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date DateOf(int y, int m, int d)
{
    Date date;
    date.y = y;
    date.m = m;
    date.d = d;

    return date;
}

Date After(Date x, int n)
{

    x.d += n; //일단 날짜를 한번에 더한다.

    int a = isleap(x.y);

    // 3월 18일 >>> 4월 18일  -- 3월의 m 을 체크

    while (mdays[a][x.m - 1] < x.d)
    {
        x.d -= mdays[a][x.m - 1];

        x.m += 1;

        if (x.m > 12)
        {
            x.y += 1; // 달 넘어가는 거
            x.m = 1;  //월 초기화
        }

        if (isleap(x.y) == 1)
        {
            a = 1;
        }
        else
        {
            a = 0; //윤년 체크!!!!!
        }
    }

    printf("반환된 날짜는 %d년 %d월 %d일 입니다.\n", x.y, x.m, x.d);
    return x;
}

int main(void)
{

    Date x[] = {
        {2002, 4, 1},
        {1995, 5, 16},
        {1999, 1, 10},
        {2008, 8, 25},
        {2017, 11, 18},
        {2021, 2, 2}};

    int nx = sizeof(x) / sizeof(x[0]);

    for (int i = 0; i < nx; i++)
    {
        printf("%d. ", i + 1);
        printf("%d년 %d월 %d일\n", x[i].y, x[i].m, x[i].d);
    }

    int k, h;
    printf("몇번째 날짜를 선택하시겠습니까?");
    scanf("%d", &k);

    printf("몇일 뒤의 날짜를 반환할까요?");
    scanf("%d", &h);

    After(x[k - 1], h);

    return 0;
}