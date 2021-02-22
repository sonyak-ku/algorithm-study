//int 형 스택 IntStack 헤더
#ifndef ___IntStack
#define ___IntStack

typedef struct
{
    int max; //스택 용량
    int ptr; // 스택 포인터
    int *stk; //스택의 첫 요소에 대한 포인터
} IntStack;

int Initialize(IntStack *s, int max);

int Push(IntStack *s, int x);

int Pop(IntStack *s, int *x);

int Peek(const IntStack *s, int *x);

void Clear(IntStack *s);

int Capacity(const IntStack *s);

int Size(const IntStack *s);

int IsEmpty(const IntStack *s);

int IsFull(const IntStack *s);

int Search(const IntStack *s, int x);

void Print(const IntStack *s);

void Terminate(IntStack *s);
#endif
