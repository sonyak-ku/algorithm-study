#ifndef __DoubleStack
#define __DoubleStack

typedef struct
{
    int max;
    int aptr; //바텀부터 이동하는 스텍포인터
    int bptr; //탑부터 이동하는 스택포인터
    int *stk; //첫요소 포인터
    
} DoubleStack;

int Initialize(DoubleStack *s, int max);

int PushA(DoubleStack *s, int x);

int PushB(DoubleStack *s, int x);

int PopA(DoubleStack *s, int *x);

int PopB(DoubleStack *s, int *x);

int SizeA(const DoubleStack *s);

int SizeB(const DoubleStack *s);

int Capacity(const DoubleStack *s);

int PeekA(const DoubleStack *s, int *x);

int PeekB(const DoubleStack *s, int *x);

void Print(const DoubleStack *s);


void Terminate(DoubleStack *s);
#endif