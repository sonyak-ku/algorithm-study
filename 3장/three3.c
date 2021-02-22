#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[]);

int main(void)
{
    int i, nx, ky, idx;
    int *x; //원래의 배열
    int *y; //원하는 키의 인덱스 값만 뽑아낸 배열

    printf("요소 개수 : ");
    scanf("%d", &nx); //요소 개수 변수가 nx

    x = calloc(nx, sizeof(int));
    y = calloc(nx, sizeof(int)); //인덱스 값만 들어갈 배열 메모리 할당

    for (i = 0; i < nx; i++)
    {
        printf("x[%d] : ", i);
        scanf("%d", &x[i]);
    }

    printf("검색값 : ");
    scanf("%d", &ky); //검색값을 ky에 저장한다.

    idx = search_idx(x, nx, ky, y); //여기까지는 되는 듯 하다!!!

    printf("찾으려는 숫자 %d는 %d개 있으며 인덱스의 배열은 이렇습니다.\n", ky, idx);
    for (int i = 0; i < idx; i++)
    {
        printf("%2d", y[i]);
    }
    free(x);
    free(y);
}

int search_idx(const int a[], int n, int key, int idx[])
{
    int count = 0;
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            count++;
        }
    } //idx 에 할당할 메모리 크기를 구하기 위해

    for (int i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            idx[p++] = i;
        }
    }

    return count;
}