#include <stdio.h>
#include "Deck.h"

int main(void)
{
    Deck d;

    if(Initialize(&d, 10) == -1)
    {   
        puts("덱의 생성에 실패하였습니다.");
        return -1;
    }

    while(1)
    {
        int m, x;

        printf("현재 데이터 수 : %d / %d \n", Size(&d), Capacity(&d));
        printf("1.인큐(front) 2.인큐(rear) 3.디큐(front) 4.디큐(rear) 5.프린트 0.종료 : ");
        scanf("%d", &m);

        if(m == 0)
        {
            break;
        }
        switch(m)
        {   
            case 1 :
                printf("데이터 : ");
                scanf("%d", &x);
                if (Enque_front(&d, x) == -1)
                {
                    puts("\a오류 : 인큐에 실패하였습니다.");
                }
                break;
            
            case 2 :
                printf("데이터 : ");
                scanf("%d", &x);
                if (Enque_rear(&d, x) == -1)
                {
                    puts("\a오류 : 인큐에 실패하였습니다.");
                }
                break;
            
            case 3 :
                if(Deque_front(&d, &x) == -1)
                {
                    puts("\a오류 : 디큐에 실패하였습니다.");
                }
                else
                {
                    printf("디큐 데이터는 %d입니다.\n", x);
                }
                break;

            case 4 :
                if(Deque_rear(&d, &x) == -1)
                {
                    puts("\a오류 : 디큐에 실패하였습니다.");
                }
                else
                {
                    printf("디큐 데이터는 %d입니다.\n", x);
                }
                break;
            
            case 5 :
                Print(&d);
                break;
        }
    }
    
    Terminate(&d);
    return 0;
}