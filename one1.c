#include <stdio.h>

int max4(int a, int b, int c, int d);

int main(void)
{
    
    printf("max4(%d, %d, %d, %d) = %d\n", 2, 4, 5, 1, max4(2, 4, 5, 1));
   

}

int max4(int a, int b, int c, int d)
{
    int max = a;
    
    if (max < b) max = b;
    if (max < c) max = c;
    if (max < d) max = d;

    return max;
}