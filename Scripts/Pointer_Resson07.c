#include <stdio.h>

void func(int a)
{
    a = a*2;
}

void print_array( int *p,int n)
{
    for(int i =0; i < n ; i++)
    {
        printf("[%p] %d (%08x)\n", p+i,*(p+i),*(p+i));
    }
}

int mystrlen(const char * str)
{
    char *ptr = (char *)str;
    while( *ptr != '\0')
    {
        ptr ++;
    }
    return ptr -str;
}

void mystrcpy(char* s2,const char* s1)
{
    int i;
    for(i = 0; *(s1 + i) != '\0' ; i++ )
    {
        *(s2 + i) = *(s1 + i);
    }

    *(s2 + i) = *(s1 + i);
}

int main(void)
{
    {//例9
        printf("例９\n");
        int a= 10;
        func(a);
        printf("%d\n", a);
    }

    {//練習8

        printf("\n練習８\n");
        int i, n, d[100];
        int *p = d;
        
        printf("n = ");
        scanf("%d", &n);

        for(i=0;i<n;i++)
        {
            scanf("%d",d + i);
        }
        
        print_array(p,n);
    }

    {//練習9
        printf("\n練習9\n");

        char s1[] = "kagawa_kosen";
        char s2[100];

        mystrcpy(s2,s1);
        printf("%s\n",s2);
    }
    {
        //練習10
        printf("\n練習１０\n");
        char str[] = "NeoVim is god";
        printf("%d\n",mystrlen(str));
    }

    return 0;
}

/*
例９
10

練習８
n = 3
100
200
300
[0x7ffe6a13e740] 100 (00000064)
[0x7ffe6a13e744] 200 (000000c8)
[0x7ffe6a13e748] 300 (0000012c)

練習9
kagawa_kosen

練習１０
13
*/
