#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;
    if (Initialize(&s, 64) == -1)   //64만큼의 크기를 가진 스택 초기화 실패시
    {
        puts("스택 생성에 실패하였습니다.");
        return -1;
    }

    while(1)
    {
        int menu, x;
        printf("현재 데이터 수 : %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (0)종료 : ");
        scanf("%d", &menu);

        if (menu == 0) break;     //스위치문 처음 쓰는거 
        switch (menu)
        {
        case 1/* constant-expression */:
            /* code */
            printf("데이터 : ");
            scanf("%d", &x);
            if (Push(&s, x) == -1)
            {
                puts("\a오류 : 푸시에 실패하였습니다.");
            }
            break;

        case 2 :
            if(Pop(&s, &x) == -1)
            {
                puts("\a 오류 : 팝에 실패하였습니다.");
            }
            else
            {
                printf("팝 데이터는 %d입니다.\n", x);
            }
            break;

        case 3 :
            if (Peek(&s, &x) == -1)
            {
                puts("\a오류 : 피크에 실패하였습니다.");
            }
            else
            {
                printf("피크 데이터는 %d입니다.\n", x);
            }
            break;

        case 4 :
            Print(&s);
            break;
        }
    }
    Terminate(&s);
    return 0;
}

   