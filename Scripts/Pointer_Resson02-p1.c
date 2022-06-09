#include <stdio.h>

typedef int *intPtr;//*のほうがやっぱりいいかな

int a, b;
// グローバル変数(初期化なし)
int c = 100, d = 200;
// グローバル変数(初期化あり)
int main(void)
{
    int e, f;
    // ローカル変数(初期化なし)

    int g = 10, h = 20;
    // ローカル変数(初期化あり)


    /* ここにプログラムを追加*/

    intPtr ap = &a;
    intPtr bp = &b;
    intPtr cp = &c;
    intPtr dp = &d;
    intPtr ep = &e;
    intPtr fp = &f;
    intPtr gp = &g;
    intPtr hp = &h;

    printf("&a = %p , a = %d\n", ap, *ap);
    printf("&b = %p , b = %d\n", bp, *bp);
    printf("&c = %p , c = %d\n", cp, *cp);
    printf("&d = %p , d = %d\n", dp, *dp);
    printf("&e = %p , e = %d\n", ep, *ep);
    printf("&f = %p , f = %d\n", fp, *fp);
    printf("&g = %p , g = %d\n", gp, *gp);
    printf("&h = %p , h = %d\n", hp, *hp);

    return 0;
}

//アドレスを出力すると0でしょきかされている
//コンパイラー gcc 12.10 (GCC)
/*
&a = 0x55f19a87c044 , a = 0
&b = 0x55f19a87c048 , b = 0
&c = 0x55f19a87c038 , c = 100
&d = 0x55f19a87c03c , d = 200
&e = 0x7ffd25ac58f8 , e = 0
&f = 0x7ffd25ac58fc , f = 0
&g = 0x7ffd25ac5900 , g = 10
&h = 0x7ffd25ac5904 , h = 20
*/