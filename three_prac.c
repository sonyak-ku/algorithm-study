#include <stdio.h>
#include <stdlib.h>

int int_cmp(const int *a, const int *b);

int main(void)
{
    int i, nx, ky;
    int *x;  //배열의 첫번째 요소에 대한 포인터
    int *p; //검색한 요소에 대한 포인터
    
    puts("bsearch 함수를 사용하여 검색");
    printf("요소 갯수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));  //nx 개수의 요소를 가진 배열 메모리 할당

    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (i = 1; i < nx; i++)
    {
        do
        {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]);  //앞의 값보다 큰수가 쓰여야지 반복문 탈출 가능(오름차순)
    }
    printf("검색값 : ");
    scanf("%d", &ky);

    //bsearch 함수 사용
    p = bsearch(&ky, x, nx, sizeof(int), (int (*)(const void *, const void *)) int_cmp); //다섯법재 인수, 함수의 표인터형 함수의 캐스팅 중요!!
     

    if(p == NULL)
    {
        puts("검색에 실패하였습니다.");
    }
    else
    {
        printf("%d은(는) x[%d]에 있습니다. \n", ky, (int)(p - x));
    }
    free(x);
}

//정수를 비교하는 함수 (오름차순)
int int_cmp(const int *a, const int *b)  // key 객체에 대한 포인터를 첫번째 인수로, 배열요소 포인터가 두번째 인수로
{
    if(*a < *b)
    {                   
        return -1;    //어떤 상황에서 배열요소 포인터가 작아질지 ex)오름차순에서 key가 더 작다면 포인터가 더 작아짐.
    }
    else if(*a > *b)
    {
        return 1;     //어떤 상황에서 배열요소 포인터가 커질지 x)오름차순에서 key가 더 크다면 포인터가 더 커짐.
    }
    else
    {
        return 0;
    }
}