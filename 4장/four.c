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
        printf("(1)푸시 (2)팝 (3)피크 (4)출력 (5)클리어 (6)Isfull (7)IsEmpty (8)Search (0)종료 : ");
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

        case 5 : 
            Clear(&s);
            printf("스택은 깨끗이 비워졌습니다.\n");
            break;

        case 6 :
            if (IsFull(&s) == 0)  //거짓(비어있지 않다면)이면 0이 리턴이 될것이다. 
            {
                printf("빈 자리가 아직 있습니다.\n");
            }
            else
            {
                printf("스택은 가득 찼씁니다!!\n");
            }
            break;

        case 7 : 
            if (IsEmpty(&s) == 0)  //거짓(비어있지 않다면)이면 0이 리턴이 될것이다. 
            {
                printf("이 스택은 비어있지 않습니다.\n");
            }
            else
            {
                printf("이 스택은 비어있습니다.\n");
            }
            break;
        
        case 8 :
            printf("찾고싶은 숫자 : ");
            scanf("%d", &x);

            if (Search(&s, x) != -1)
            {
                printf("찾고자 하는 숫자 %d는 s->ptr[%d]에 있습니다.", x, Search(&s, x));
                putchar('\n');
            }
            else
            {
                printf("찾고자하는 숫자 %d는 이 스택에 존재하지 않습니다.", x);
                putchar('\n');
            }
            break;
       }
    }
    Terminate(&s);
    return 0;
}

   