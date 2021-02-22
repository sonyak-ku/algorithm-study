#include <stdio.h>
#include <stdlib.h>

int bin_search(const int a[], int n, int key);

int main(void)
{
    int i, nx, ky, idx;
    int *x;

    printf("요소 개수 : ");
    scanf("%d", &nx); //요소 개수 변수가 nx
    x = calloc(nx, sizeof(int));
    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("검색값 : ");
    scanf("%d", &ky); //검색값을 ky에 저장한다.

    idx = bin_search(x, nx, ky);

    if (idx == -1)
    {
        puts("검색에 실패했습니다.");
    }
    else
    {
        printf("%d 는 x[%d] 에 있습니다.\n", ky, idx);
    }
    free(x);
}

int bin_search(const int a[], int n, int key)
{
    int i;
    int pl = 0;
    int pr = n - 1;

    //윗라인
    printf("   |");
    for (int j = 0; j < n; j++)
    {
        printf("%2d", j);
    }
    printf("\n");
    printf("---+");
    for (int j = 0; j < n; j++)
    {
        printf("---");
    }             // ----------------------- 여기까진 공통인듯.
    printf("\n"); //헤드 부분 완성

    do
    {
        int pc = (pl + pr) / 2; //중앙요소 인덱스 정하기
        printf("   |");

        for (int i = 0; i <= pr; i++)
        {
            if (i == pl)
            {
                printf("<-");
            }
            else if (i == pc)
            {
                printf("+");
            }
            else if (i == pr)
            {
                printf("->");
            }
            else
            {
                printf("  ");
            }
        } //화살표 그려지는 라인 완성
        printf("\n");
        printf("  %d|", pc);
        for (int j = 0; j < n; j++)
        {
            printf("%2d", a[j]);
        } // 배열의 요소가 그려지는 라인
        printf("\n");

        if (a[pc] == key)
        {
            return pc;
        }
        else if (a[pc] < key)
        {
            pl = pc + 1;
        }
        else
        {
            pr = pc - 1;
        }
    } while (pl <= pr);

    return -1;
}