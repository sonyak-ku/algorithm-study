#include <stdio.h>

int card_convr(unsigned x, int n, char d[]);

int main(void)
{
    unsigned no; //변환하는 정수
    int cd; //기수
    int dno; //변환 후 자리수
    char cno[512];
    int retry;

    printf("10진수를 기수 변환합니다.\n");
    do
    {
        printf("변환하려는 음이 아닌 정수 : ");
        scanf("%u", &no);

        do
        {
            printf("어떤 진수로 변환할까요?(2-36)");
            scanf("%i", &cd);
        }while (cd < 2 || cd > 36 );

        dno = card_convr(no, cd, cno);
        printf("%d진수로는", cd);

        for (int i = dno - 1; i >= 0; i--)
        {
            printf("%c",cno[i]);
        }    

        printf("입니다\n");
        printf("한번 더 할까요?(1 -- 예/ 0 -- 아니오) : ");
        scanf("%i", retry);
    } while (retry == 1);
    

}

int card_convr(unsigned x, int n, char d[])
{
    char dchar[]="0123456789ABCDEFGHIJKLNMOPQRSTUVWXYZ";
    int digits = 0;  
    
    if (x == 0) 
        {
            d[digits++] = dchar[0];
        }
    else{
        while(x)
        {
            d[digits++] = dchar[x % n];
            x /= n;
        } 
    }
    for (int i = 0, tmp = 0; i < digits/2; i++)
    {   
        tmp = d[i];
        d[i] = d[digits-1-i];
        d[digits-1-i] = tmp;
    }
    return digits;
}