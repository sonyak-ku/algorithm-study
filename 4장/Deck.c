#include <stdio.h>
#include <stdlib.h>
#include "Deck.h"

int Initialize(Deck *d, int max)
{
    d->num = d->front = d->rear = 0;
    if ((d->que = calloc(max, sizeof(int))) == NULL)
    {
        d->max = 0;
        return -1;
    }
    d->max = max;
    return 0;
}

int Enque_front(Deck *d, int x)
{
    if (d->num >= d->max)
    {
        return -1;
    }
    else
    {
        d->num++;       
        if (d->front == 0)
        {
            d->front = d->max - 1;
            d->que[d->front] = x;
        }
        else
        {
            d->que[--d->front] = x;
        }
        return 0;
    }
}

int Enque_rear(Deck *d, int x)
{
    if (d->num >= d->max)
    {
        return -1;
    }
    else   //요소를 넣을 수 있는 상태이다. 
    {
        d->num++;
        d->que[d->rear++] = x;
        if (d->rear == d->max)
        {
            d->rear = 0;
        }
        return 0;
    }
}

int Deque_front(Deck *d, int *x)
{
    if(d->num <= 0)
    {
        return -1;
    }
    else
    {
        d->num--;
        *x = d->que[d->front++];
        if (d->front == d->max)
        {
            d->front = 0;
        }
        return 0;
    }
}

int Deque_rear(Deck *d, int *x)
{
    if(d->num <= 0)
    {
        return -1;
    }
    else
    {
        d->num--;
        if (d->rear == 0)
        {
            d->rear = d->max - 1;
            *x = d->que[d->rear];
        }
        else
        {
            *x = d->que[--d->rear];
        }
        return 0;
    }
}

int Size(const Deck *d)
{
    return d->num;
}

int Capacity(const Deck *d)
{
    return d->max;
}

void Print(const Deck *d)
{
    int i;
    printf("front ");
    for (i = 0; i < d->num; i++)
    {
        printf(" %d", d->que[(i + d->front) % d->max]);
    }
    printf("rear ");
    putchar('\n');
}

void Terminate(Deck *d)
{
    if (d->que != NULL)
    {
        free(d->que);
    }
    d->max = d->front = d->rear = d->num = 0;
}