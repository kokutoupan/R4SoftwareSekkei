#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) 
{
    {//練習11
        printf("練習10\n");
        char s[100];
        scanf("%s",s);

        int str_size = strlen(s);
        if(str_size == 0)
            return 0;

        char *p = (char *)malloc(sizeof(char) * (str_size +1));
        if(p == NULL)
        {
            puts("memory allocation error\n");
            return 0;
        }

        for(int i = 0; i < str_size ; i++)
        {
            p[i] = s[str_size-i-1]; 
        }
        p[str_size] = s[str_size];

        printf("%s\n", p);

        free(p);

    }
    {//練習12
        int n ,*ptr =NULL;

        printf("n=");
        scanf("%d",&n);

        ptr = (int *)malloc( sizeof(int) * n);

        for(int i = 0; i< n; i++)
        {
            scanf("%d",ptr + i);
        }

        for(int i= 0;i < n; i++)
        {
            printf("[%p]",ptr + i);
            for(int j=0; j< sizeof(int); j++)
            {
                printf(" %02x",*((unsigned char *)(ptr + i) + j));
            }
            printf("\n");
        }

        free(ptr);
    }

    return 0;
}

/*
練習10
kanazawa
awazanak
n=4
1
10
100
1000
[0x56235f000ac0] 01 00 00 00
[0x56235f000ac4] 0a 00 00 00
[0x56235f000ac8] 64 00 00 00
[0x56235f000acc] e8 03 00 00
*/
