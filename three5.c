int bin_search2(const int a[], int n, int key)
{
    int pl = 0;
    int pr = n - 1;
    int pc;
   do
   {
       pc = (pl + pr) / 2;
       if(a[pc] == key) // 원하는 키 값을 찾았을때
       {
           //원하는 키값과 같은 요소가 앞에 있는지를 검사하기 위해 반복문 탈출.
            break;
           
       }
       else if(a[pc] < key)
       {
           pl = pc + 1;
       }
       else
       {
           pr = pc - 1;
       }
   } while(pl <= pr);
    // 배열의 앞 요소 검사하기
    do
    {
       if(a[pc] == a[pc-1])
       {
           pc--;  // 앞에 같은 요소가 존재한다면 , pc 값을 하나씩 줄여나간다.
       }
       else
       {
           return pc; // 그렇지 않은 경우가 생겼을 때에 pc 값을 리턴한다.
       }
    } while (pc);  // 조건은 그다지 중요하지 않아서 그냥 pc가 양수면 계속 돌게함. 어짜피 다른값나오면 알아서 리턴되고 종료됨.

    return -1;
}