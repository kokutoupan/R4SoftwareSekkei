#include <stdio.h>

void myregister(int *money,const int coin)
{
  if(*money<coin)
    return ;
  printf("%d円玉 =%d枚\n",coin,*money / coin);
  *money%=coin;
}

int main(void)
{
  int coinnum=6;
  int coins[6]={500,100,50,10,5,1};
  int buy,insert;
  printf("購入金額 = ");
  scanf("%d",&buy);
  printf("投入金額 = ");
  scanf("%d",&insert);

  int oturi=insert-buy;
  if(oturi<0)
  {
    printf("お金が足りません\n");
    return 0;
  }
  else
  {
    printf("%d円のおつりです\n",oturi);
  }

  for(int i=0;i<coinnum;i++)
  {
    myregister(&oturi,coins[i]);
  }

  return 0;
}

/*
購入金額 = 1011
投入金額 = 41241
40230円のおつりです
500円玉 =80枚
100円玉 =2枚
10円玉 =3枚
*/