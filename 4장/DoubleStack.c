#include <stdio.h>
#include <stdlib.h>
#include "DoubleStack.h"

int Initialize(DoubleStack *s, int max)
{
    s->aptr = 0;       //아래에서 쌓이고, 그대로가 개수다.
    s->bptr = max - 1; //위에서쌓이고, max- 1 에서 bptr뺀값이 개수이다.
    // aptr이든 bptr이든 배열의 인덱스 값 안에서 놀게끔 하고 싶다.
    if ((s->stk = calloc(max, sizeof(int))) == NULL) //배열 생성 실패, 메모리 할당 실패햇을 대
    {                                                // 이부분은 어케 처리할까, bstk도 메모리할당..//bstk 필요없는듯
        s->max = 0;
        return -1;
    }

    s->max = max;

    return 0;
} // ---------------------여기까지는 터치 안해도 될듯

int PushA(DoubleStack *s, int x)
{
    if (s->aptr >= s->bptr + 1) //+1 을 한 이유는, 양쪽에서 쌓이는 배열구조
    {                           //이더라도, 한쪽이 쌓이지 않는다면, IntStack과 똑같이 작용해야함.
        return -1;              //IntStack은 push 에서 ptr >= max일 것을 조건으로함
    }
    s->stk[s->aptr++] = x; //aptr과 bptr이 둘다 46과 46이더라도
    return 0;              //하나의요소가 들어갈 자리는 존재한다는 점이 핵심
}

int PushB(DoubleStack *s, int x)
{
    if (s->bptr <= s->aptr - 1) //위에서부터 쌓이는 애랑 만나면안되
    {                           //위와 같은 의미에서, bptr도 max만큼의 요소를 담으려면 aptr-1을 만나는걸조건걸어야
        return -1;
    }
    s->stk[s->bptr--] = x; //이렇게 구조 짜는게 맞는건가? 읽는건 내가 시키는대로니 맞을 거 같긴한데
    return 0;
}
//-------------------------------------여기까지는 거의 완벽할 정도로 잘한듯
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
    if (s->bptr >= s->max - 1)
    {
        return -1;
    }
    *x = s->stk[++s->bptr];
    return 0;
}
//여기까지는 너무 잘한것 같다 ㅎㅎ

int SizeA(const DoubleStack *s)
{
    return s->aptr;
}

int SizeB(const DoubleStack *s)
{
    return (s->max - 1) - s->bptr;
}

int Capacity(const DoubleStack *s)
{
    return s->max;
}

int PeekA(const DoubleStack *s, int *x)
{
    if (s->aptr <= 0)
    {
        return -1;
    }
    *x = s->stk[s->aptr - 1];
    return 0;
}

int PeekB(const DoubleStack *s, int *x)
{
    if (s->bptr >= s->max - 1)
    {
        return -1;
    }
    *x = s->stk[s->bptr + 1];
    return 0;
}

void Print(const DoubleStack *s)
{
    int i;
    puts("A스택의 요소");
    for (i = 0; i < s->aptr; i++)
    {
        printf("%d ", s->stk[i]);
    }
    putchar('\n'); //a 스택 출력하기

    puts("B스택의 요소");
    for (i = s->max - 1; i > s->bptr; i--)
    {
        printf("%d ", s->stk[i]);
    }
    putchar('\n'); //b 스택 출력하기
}

void Terminate(DoubleStack *s)
{
    if (s->stk != NULL)
    {
        free(s->stk);
    }
    s->max = s->aptr = s->bptr = 0;
}