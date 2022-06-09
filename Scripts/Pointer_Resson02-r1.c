#include <stdio.h>

int main(void)
{
    int a;
    printf("&a = %p byte\n",&a);

    //中身の確認
    printf("\n%lx\n",&a);
    return 0;
}

/*
&a = 0x7ffe1945d314 byte

7ffe1945d314
*/
