#include <stdio.h>


int min3(int a, int b, int c)
{
    int min = a;
    
    if (min > b) min = b;
    if (min > c) min = c;
    

    return min;
}



int main(void)
{
    
    printf("max4(%d, %d, %d, %d) = %d\n", 2, 4, 5, 1, max4(2, 4, 5, 1));
   

}

