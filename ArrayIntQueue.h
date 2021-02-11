#ifndef __ArrayIntQueue
#define __ArrayIntQueue

typedef struct
{
    int max; // 큐의용량
    int num; // 큐의 현재 데이터 수
    int *que; // 큐의 첫 요소에 대한 포인터
} ArrayIntQueue;

int Initialize(ArrayIntQueue *q, int max);

int Enque(ArrayIntQueue *q, int x);

int Deque(ArrayIntQueue *q, int *x); //pop과 같은 이치일듯

int Size(const ArrayIntQueue *q);

int Capacity(const ArrayIntQueue *q);

int Peek(const ArrayIntQueue *q, int *x);

void Print(const ArrayIntQueue *q);

void Terminate(ArrayIntQueue *q);
#endif
