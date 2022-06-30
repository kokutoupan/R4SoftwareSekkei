#include <stdio.h>

int main(void) {
    int a[100] ;
    int i,j;
    printf("i = ");
    scanf("%d", &i);
    printf("j = ");
    scanf("%d", &j);

    printf("&a[%2d] = %p\n", i, a + i);
    printf("&a[%2d] = %p\n", j, a + j);

    printf("%ld byteの差があります\n", ((a + j) - (a + i)) * sizeof(int)) ;
    return 0;
}

/*
i = 0
j = 99
&a[ 0] = 0x7ffdc6de8ba0
&a[99] = 0x7ffdc6de8d2c
396 byteの差があります

i = 24
j = 64
&a[24] = 0x7ffee3fd6150
&a[64] = 0x7ffee3fd61f0
160 byteの差があります
*/
