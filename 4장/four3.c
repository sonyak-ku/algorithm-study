#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void)
{
    ArrayIntQueue q;
    if (Initialize(&q, 64) == -1) //64만큼의 크기를 가진 큐초기화 실패시
    {
        puts("큐 생성에 실패하였습니다.");
        return -1;
    }

    while (1)
    {
        int menu, x;
        printf("현재 데이터 수 : %d / %d\n", Size(&q), Capacity(&q));
        printf("(1)enque (2)deque (3)피크 (4)출력 (0)종료 : ");
        scanf("%d", &menu);

        if (menu == 0)
            break; //스위치문 처음 쓰는거
        switch (menu)
        {
        case 1 /* constant-expression */:
            /* code */
            printf("데이터 : ");
            scanf("%d", &x);
            if (Enque(&q, x) == -1)
            {
                puts("\a오류 : enque에 실패하였습니다.");
            }
            break;

        case 2:
            if (Deque(&q, &x) == -1)
            {
                puts("\a 오류 : deque에 실패하였습니다.");
            }
            else
            {
                printf("deque 데이터는 %d입니다.\n", x);
            }
            break;

        case 3:
            if (Peek(&q, &x) == -1)
            {
                puts("\a오류 : 피크에 실패하였습니다.");
            }
            else
            {
                printf("피크 데이터는 %d입니다.\n", x);
            }
            break;

        case 4:
            Print(&q);
            break;
        }
    }
    Terminate(&q);
    return 0;
}