#include <stdio.h>
#include <stdlib.h>

void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));
int cmp(const int *a, const int *b);

int main(void)
{
    int i, nx, ky;
    int *x;
    int *p; // 찾으려는 대상 저장 포인터 

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

    p = seqsearch(&ky, x, nx, sizeof(int), (int(*)(const void *, const void *))cmp);  //찾아낸 요소에 대한 포인터가 들어가는 자리

    if (p == NULL)
    {
        puts("검색에 실패했습니다.");
    }
    else
    {
        printf("%d은(는) x[%i]에 있습니다. \n", ky, (int)(p - x));
    }
    printf("x의 포인터 값은 %i 이다.", (int)x);
    printf("x의 포인터는 %i 이다.", *x);
    putchar('\n');

    printf("p의 포인터는 %i 이다.", (int)p);
    printf("p의 포인터는 %i 이다.", *p);
    putchar('\n');

    printf("x의 주소는 %p 이다.", x);
    printf("p의 주소는 %p 이다.", p);
    putchar('\n');

    printf("%i", (int)(p-x));
    putchar('\n');

    free(x);              //대강 구조는 짯고.

}
//선형검색알고리즘, 대상정렬되어있지 않아도된다. 
void *seqsearch(const void *key, const void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{

    for (int i = 0, k; i < nmemb; i++)
    {
        k = i * size; //포인터의 주소값은 한칸당, 사이즈만큼 이동하기 때문에

        if((*compar)(key, base+k) == 0)  // 함수 포인터를 이용하여 조건에 맞으면 값 반환하도록 한다. 
        {
            return (void *)(base+k);  // 해당 주소값 반환할 수 있도록하기
        }
        //리턴 값이 1이 나왔을 듯, 그런경우에 앞라인으로 이동할 수 있도록 함.
   
    }
   

    return NULL;
}

int cmp(const int *a, const int *b)    //정렬되있지 않기 때문에 앞뒤로 간다기 보다는, 다르면 그냥 앞으로만 탐색하도록.
{
    if(*a == *b)
    {
        return 0;
    }
    else
    {
        return 1;   
    }
}