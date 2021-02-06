#include <stdio.h>
#include <stdlib.h>

void *binsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
int cmp(const int *a, const int *b);

int main(void)
{
    int i, nx, ky;
    int *x; //배열의 첫번째 요소에 대한 포인터
    int *p; //검색한 요소에 대한 포인터

    puts("bsearch 함수를 사용하여 검색");
    printf("요소 갯수 : ");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int)); //nx 개수의 요소를 가진 배열 메모리 할당

    printf("오름차순으로 입력하세요.\n");
    printf("x[0] : ");
    scanf("%d", &x[0]);
    for (i = 1; i < nx; i++)
    {
        do
        {
            printf("x[%d] : ", i);
            scanf("%d", &x[i]);
        } while (x[i] < x[i - 1]); //앞의 값보다 큰수가 쓰여야지 반복문 탈출 가능(오름차순)
    }
    printf("검색값 : ");
    scanf("%d", &ky);

    p = binsearch(&ky, x, nx, sizeof(int), (int (*)(const void *, const void *))cmp); //찾아낸 요소에 대한 포인터가 들어가는 자리

    if (p == NULL)
    {
        puts("검색에 실패했습니다.");
    }
    else
    {
        printf("%d은(는) x[%i]에 있습니다. \n", ky, (int)(p - x));
    }

    free(x); //대강 구조는 짯고.
}
//이진검색알고리즘, 대상정렬되어있다 오름차순으로
void *binsearch(const void *key, const void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *))
{
    int pl = 0;
    int pr = nmemb - 1;
    int k;
    int y = 1; // 같은 키값 체크를 위해 몇 번 앞으로 가야하는지 횟수를 세기 위함  
    do
    {
        int pc = (pl + pr) / 2;
        k = pc * size; //중간 사이즈만큼 포인터를 이동시키려는 목적

        if ((*compar)(key, base + k) == 1)
        {
            pl = pc + 1;
        }
        else if ((*compar)(key, base + k) == -1)
        {
            pr = pc - 1;
        }
        else // 원하는 키값을 찾았다
        {   
            if ((*compar)(base + k, base + k - (y*size)) == 0) //최소 하나는 같은 숫자가 앞에 존재한다는 경우
            {
                do
                {
                    y++;
                } while ((*compar)(base + k, base + k - (y*size)) == 0); //y가 원래값보다 하나 높은 채로 넘겨진다
                y -= 1; // 원래값으로 y를 돌리기위해 1을 빼준다.
                return (void *)(base + k - (y*size));
            }
            else 
            {        
                return (void *)(base + k);
            }
        }
    } while (pl <= pr);
    return NULL; //원하는 키값을 찾지 못하였을때.
}

int cmp(const int *a, const int *b) //정렬되있지 않기 때문에 앞뒤로 간다기 보다는, 다르면 그냥 앞으로만 탐색하도록.
{
    if (*a < *b)
    {
        return -1;
    }
    else if (*a > *b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}