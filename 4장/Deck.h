#ifndef ___Deck
#define ___Deck

typedef struct
{
    int max;
    int num;
    int front;
    int rear;
    int *que;
} Deck;

int Initialize(Deck *d, int max);

int Enque_front(Deck *d, int x);

int Deque_front(Deck *d, int *x);

int Enque_rear(Deck *d, int x);

int Deque_rear(Deck *d, int *x);

int Size(const Deck *d);

int Capacity(const Deck *d);

void Print(const Deck *d);

void Terminate(Deck *d);
#endif