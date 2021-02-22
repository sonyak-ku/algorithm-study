#include <stdio.h>

typedef struct
{
    int y;
    int m;
    int d;
}
Date;

int main(void)
{
    
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
    x.d += n;
    return x;
}

Date Before(Date x, int n)
{
    x.d -= n;
    return x;
}