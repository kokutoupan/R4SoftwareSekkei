#include <stdio.h>


int main(void) {
    {
        printf("例５\n");
        char *pa = NULL;
        int *pb = NULL;
        double *pc = NULL;

        printf("pa=%p pa+1=%p\n", pa, pa+1);
        printf("pb=%p pb+1=%p\n", pb, pb+1);
        printf("pc=%p pc+1=%p\n", pc, pc+1);
    }

    {
        printf("\n例６\n");
        char s[100];
        char *p = s; //s は &s[0]と同じ(char* 型)
        int i = 0;

        printf("str = "); scanf("%s", p);//文字列入力

        while(*(p + i) !='\0') {
            printf("[%p]: %c\n", p+i, *(p+i));
            i++;
        }
    }
    {
        printf("\n練習5\n");
        char s[100];
        char *p = s; //s は &s[0]と同じ(char* 型)

        printf("str = "); scanf("%s", p);//文字列入力

        while(*p !='\0') {
            printf("[%p]: %c\n", p, *p);
            p++;
        }
    }

    {
        printf("\n例７\n");

        int d[] = { 1, 10, 100, 1000, 10000};
        int *p = d;
        int i,n;

        n = sizeof(d)/sizeof(d[0]);

        for(i = 0; i<n; i++)
            printf("[%p]: %d\n", p+i, *(p+i));
    }

    {
        printf("\n例８\n");
        int a = 1234567;
        unsigned char *p = (unsigned char *)&a;

        printf("%02x\n", *p);
    }

    {
        printf("\n練習６\n");
        int a = 1234567;

        for(unsigned char *p = (unsigned char *)&a; p < (unsigned char *)&a + sizeof(a); ++p )
            printf("[%p]: %02x\n", p, *p);
    }
    return 0;
}

/*
例５
pa=(nil) pa+1=0x1
pb=(nil) pb+1=0x4
pc=(nil) pc+1=0x8

例６
str = takuma
[0x7ffe28307d00]: t
[0x7ffe28307d01]: a
[0x7ffe28307d02]: k
[0x7ffe28307d03]: u
[0x7ffe28307d04]: m
[0x7ffe28307d05]: a

練習5
str = takuma
[0x7ffe28307d00]: t
[0x7ffe28307d01]: a
[0x7ffe28307d02]: k
[0x7ffe28307d03]: u
[0x7ffe28307d04]: m
[0x7ffe28307d05]: a

例７
[0x7ffe28307ce0]: 1
[0x7ffe28307ce4]: 10
[0x7ffe28307ce8]: 100
[0x7ffe28307cec]: 1000
[0x7ffe28307cf0]: 10000

例８
87

練習６
[0x7ffe28307c90]: 87
[0x7ffe28307c91]: d6
[0x7ffe28307c92]: 12
[0x7ffe28307c93]: 00
*/
