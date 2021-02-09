#include <stdio.h>
#include <stdlib.h>
#include "IntStack.h"

int Initialize(IntStack *s, int max)
{
    s->ptr = 0;
    if ((s->stk = calloc(max, sizeof(int))) == NULL) //배열 생성 실패, 메모리 할당 실패햇을 대
    {
        s->max = 0;
        return -1;
    }

    s->max = max; //배열 메모리 할당 성공. 초기화 성공
    return 0;
}

int Push(IntStack *s, int x)
{
    if (s->ptr >= s->max)
    {
        return -1;
    }
    s->stk[s->ptr++] = x;
    return 0;
}

int Pop(IntStack *s, int *x) //살짝 이해가 안되는 곳.
{
    if (s->ptr <= 0)
    {
        return -1;
    }
    *x = s->stk[--s->ptr]; // 이 코드가 이해가 안된다.  --> 코드수정, 후위 증가에서 전위 증가연산자로, 그럼에도 삭제는 어디서 시킨다는건지 ..
    return 0;              //peek 와의 차이는, 스택포인터가 변화하냐 안하냐 의 차이. pop은 ptr이 변화, peek는 변화하지 않는다.
}

int Peek(const IntStack *s, int *x)
{
    if (s->ptr <= 0)
    {
        return -1;
    }
    *x = s->stk[s->ptr - 1]; //이런 코드라면 pop과 peek 의 기능 차이가 없어보인다는 것이 단점이 될 것 같다.
    return 0;
}

void Clear(IntStack *s)
{
    s->ptr = 0; //비우기 !    ---> 이것으로 본다면, ptr을 낮추는 것을 곧 요소의 삭제라고 받아들이는 것 같아보인다 . ->> pop삭제가 흠.
}

int Capacity(const IntStack *s)
{
    return s->max;
}

int Size(const IntStack *s)
{
    return s->ptr;
}

int IsEmpty(const IntStack *s)
{
    return s->ptr <= 0;
}

int IsFull(const IntStack *s)
{
    return s->ptr >= s->max;
}

int Search(const IntStack *s, int x) //스캔방향은 top to bottom
{
    int i;
    for (i = s->ptr - 1; i >= 0; i--)
    {
        if (s->stk[i] == x)
        {
            return i;
        }
    }
    return -1;
}

void Print(const IntStack *s) //  바닥부터 꼭대기 방향으로 스캔
{
    int i;
    for (i = 0; i < s->ptr; i++)
    {
        printf("%d\n", s->stk[i]);
    }
    putchar('\n');
}

void Terminate(IntStack *s)
{
    if (s->stk != NULL)
    {
        free(s->stk);
    }
    s->max = s->ptr = 0;
}