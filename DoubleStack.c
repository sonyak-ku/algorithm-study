#include <stdio.h>
#include <stdlib.h>
#include "DoubleStack.h"

int Initialize(DoubleStack *s, int max)
{
    s->aptr = 0; //아래에서 쌓이고, 그대로가 개수다. 
    s->bptr = max - 1; //위에서쌓이고, max- 1 에서 bptr뺀값이 개수이다. 
    
    if ((s->stk = calloc(max, sizeof(int))) == NULL) //배열 생성 실패, 메모리 할당 실패햇을 대
    {    // 이부분은 어케 처리할까, bstk도 메모리할당..//bstk 필요없는듯
        s->max = 0;
        return -1;
    }

    s->max = max;
    
    return 0;
}      // ---------------------여기까지는 터치 안해도 될듯

int PushA(DoubleStack *s, int x)
{
    if (s->aptr >= s->bptr) //위에서부터 쌓이는 애랑 만나면안되
    {
        return -1;
    }
    s->stk[s->aptr++] = x;
    return 0;
}

int PushB(DoubleStack *s, int x)
{
    if (s->bptr <= s->aptr) //위에서부터 쌓이는 애랑 만나면안되
    {
        return -1;
    }
    s->stk[s->bptr--] = x; //이렇게 구조 짜는게 맞는건가? 읽는건 내가 시키는대로니 맞을 거 같긴한데
    return 0;
}
//-------------------------------------여기까지도 괜찮게 맞는거같음 
int PopA(DoubleStack *s, int *x)
{
    if (s->aptr <= 0)
    {
        return -1;
    }
    *x = s->stk[--s->aptr];
    return 0;
}

int PopB(DoubleStack *s, int *x)
{
    if (s->bptr >= s->max)
    {
        return -1;
    }
    *x = s->stk[--s->aptr];
    return 0;
}