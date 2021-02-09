#ifndef __DoubleStack
#define __DoubleStack

typedef struct
{
    int max;
    int aptr; //바텀부터 이동하는 스텍포인터
    int bptr; //탑부터 이동하는 스택포인터
    int *stk; //밑에서 위로 쌓이는 첫요소 포인터
    
} DoubleStack;

int Initialize(DoubleStack *s, int max);

int PushA(DoubleStack *s, int x);

int PushB(DoubleStack *s, int x);

int PopA(DoubleStack *s, int *x);

int PopB(DoubleStack *s, int *x);



void Terminate(DoubleStack *s);
#endif