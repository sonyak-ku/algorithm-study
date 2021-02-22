#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    int a;
 
    printf("숫자를 입력해주세요 : ");
    scanf("%d", &a); 

    int digit = 0;  // 여기서 0 으로 초기화를 안시켜서 1씩 못더했기 때문에 오류났고.
    
    for (int i = a; i > 0; i = i/10)   ////여기서 포문을 빠져나오지 못한거였습니다!!!! 그 이유는 모듈로가 나머지를 구하는 것. 정수나누기 ㄱ
    {
        digit++;
    }

    printf("그 수는 %d자리입니다.\n", digit);

}