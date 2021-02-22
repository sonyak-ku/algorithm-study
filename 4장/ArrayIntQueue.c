#include <stdio.h>
#include <stdlib.h>
#include "ArrayIntQueue.h"

int Initialize(ArrayIntQueue *q, int max)
{
    q->num = 0;
    if ((q->que = calloc(max, sizeof(int))) == NULL)
    {
        q->max = 0;
        return -1;
    }

    q->max = max;
    return 0;
} //큐 초기화, 현재 요소개수를 0으로 하며, 큐의 용량만큼 데이터 할당.

int Enque(ArrayIntQueue *q, int x)
{
    if (q->num >= q->max)
    {
        return -1;
    }
    q->que[q->num++] = x;
    return 0;
}

int Deque(ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)
    {
        return -1;
    }
    *x = q->que[0]; // 첫 요소를 밖으로 보내고

    for (int i = 1; i < q->num; i++) //요소를 하나씩 앞으로 당긴다.
    {
        q->que[i - 1] = q->que[i]; //한칸씩 댕겨서 다시저장.
    }
    q->num--; //큐의 현재데이터 개수를 하나 줄인다.

    return 0;
}

int Capacity(const ArrayIntQueue *q)
{
    return q->max;
}

int Size(const ArrayIntQueue *q)
{
    return q->num;
}

int Peek(const ArrayIntQueue *q, int *x)
{
    if (q->num <= 0)
    {
        return -1;
    }
    *x = q->que[0];
    return 0;
}

void Print(const ArrayIntQueue *q)
{
    int i;
    printf("front ");
    for (i = 0; i < q->num; i++)
    {
        printf("%d ", q->que[i]);
    }
    printf("rear");
    putchar('\n');
}

void Terminate(ArrayIntQueue *q)
{
    if (q->que != NULL)
    {
        free(q->que);
    }
    q->max = q->num = 0;
}