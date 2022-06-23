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
/* -Ofast (gccでの最適化を有効に使用した際)
&a = 0x5648e287d048 , a = 0
&b = 0x5648e287d044 , b = 0
&c = 0x5648e287d03c , c = 100
&d = 0x5648e287d038 , d = 200
&e = 0x7ffc9de6dcb8 , e = 1254846768
&f = 0x7ffc9de6dcbc , f = 32758
&g = 0x7ffc9de6dcc0 , g = 10
&h = 0x7ffc9de6dcc4 , h = 20
*/


//コンパイラー clang version 13.0.1
/*
&a = 0x564b895b2044 , a = 0
&b = 0x564b895b2048 , b = 0
&c = 0x564b895b2038 , c = 100
&d = 0x564b895b203c , d = 200
&e = 0x7ffe010cbc94 , e = 0
&f = 0x7ffe010cbc90 , f = 13
&g = 0x7ffe010cbc8c , g = 10
&h = 0x7ffe010cbc88 , h = 20
*/