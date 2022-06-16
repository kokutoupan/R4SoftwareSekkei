#include <stdio.h>

int a;

int main(void)
{
    { //練習２
        printf("練習2\n");
        char a;
        int b;
        double c;
        char *ap = &a;
        int *bp =&b;
        double *cp=&c;
        printf("&a: %u byte\n", sizeof(ap));
        printf("a:  %u byte\n", sizeof(*ap));
        printf("&b: %u byte\n", sizeof(bp));
        printf("b:  %u byte\n", sizeof(*bp));
        printf("&c: %u byte\n", sizeof(cp));
        printf("c:  %u byte\n", sizeof(*cp));
    }

    {//練習３
        printf("\n練習3\n");

        int b;

        int *ap =&a;
        int *bp = &b;

        printf("&ap %p\n",&ap);
        printf("&bp %p\n",&bp);
    }

    {//例４
        printf("\n例４\n");
        
        int a,b;
        int  *p = &a;

        scanf("%d",p);
        printf("a = %d\n",a);
    }
    return 0;
}

/*
練習2
&a: 8 byte
a:  1 byte
&b: 8 byte
b:  4 byte
&c: 8 byte
c:  8 byte

練習3
&ap 0x7fffffffd988
&bp 0x7fffffffd990

例４
219
a = 219
*/