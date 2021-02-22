#include <stdio.h>
#include <stdlib.h>

int search_detail(int a[], int n, int key);

int main(void)
{
    int i, nx, ky ,idx;
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

    idx = search_detail(x, nx, ky);

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

int search_detail(int a[], int n, int key)
{
    int i; 
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
    }
    printf("\n");   //아랫라인   
    for (i = 0; i < n; i++)
    {   
        printf("   |");
        for (int j = 0; j < i; j++)
        {
            printf("  ");
        }
        printf(" *\n");
        // 별표가 그려지는 라인 
        printf("  %d|", i); 
        for (int j = 0; j < n; j++)
        {
            printf("%2d", a[j]);
        } // 배열의 요소가 그려지는 라인

        printf("\n");
        if (a[i] == key)
        {
            return i;
        }   // 검색하려는 값이 맞는지 체크, 발견하면 함수 종료.  
    } 
    return -1; 
}