#include <stdio.h>
#include "DoubleStack.h"

int main(void)
{
    DoubleStack s;
    if (Initialize(&s, 4) == -1)
    {
        puts("스택 생성에 실패하였습니다.");
        return -1;
    }

    while (1)
    {
        int menu, x;
        printf("현재 스택A 데이터 수 : %d / %d\n", SizeA(&s), Capacity(&s));
        printf("현재 스택B 데이터 수 : %d / %d\n", SizeB(&s), Capacity(&s));
        printf("(1)푸시A (2)푸시B (3)팝A (4)팝B (5)피크A (6)피크B (7)출력 (0)종료 : ");
        scanf("%d", &menu);

        if (menu == 0)
            break;
        switch (menu)
        {
        case 1:
            printf("데이터 :");
            scanf("%d", &x);
            if (PushA(&s, x) == -1)
            {
                puts("\a오류 : 푸시에 실패하였습니다.");
            }
            break;

        case 2:
            printf("데이터 :");
            scanf("%d", &x);
            if (PushB(&s, x) == -1)
            {
                puts("\a오류 : 푸시에 실패하였습니다.");
            }
            break;

        case 3:
            if (PopA(&s, &x) == -1)
            {
                puts("\a 오류 : 팝에 실패하였습니다.");
            }
            else
            {
                printf("A스택 팝 데이터는 %d입니다.\n", x);
            }
            break;

        case 4:
            if (PopB(&s, &x) == -1)
            {
                puts("\a 오류 : 팝에 실패하였습니다.");
            }
            else
            {
                printf("B스택 팝 데이터는 %d입니다.\n", x);
            }
            break;

        case 5:
            if (PeekA(&s, &x) == -1)
            {
                puts("\a오류 : 피크에 실패하였습니다.");
            }
            else
            {
                printf("A스택 피크 데이터는 %d입니다.\n", x);
            }
            break;

        case 6:
            if (PeekB(&s, &x) == -1)
            {
                puts("\a오류 : 피크에 실패하였습니다.");
            }
            else
            {
                printf("B스택 피크 데이터는 %d입니다.\n", x);
            }
            break;

        case 7:
            Print(&s);
            break;
        }
    }
    Terminate(&s);
    return 0;
}