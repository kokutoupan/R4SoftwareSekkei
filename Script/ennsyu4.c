#include <stdio.h>

char kaidoku(char c,char base,int difarense,int size)
{
    return (c-base-difarense+size)%(size)+base;
}

int main(int argc,char ** argv )
{
    if(argc<2)
    {
        printf("引数がたりません\n");
        return 0;
    }
    FILE *fp;
    for(int i=1;i<argc;i++)
    {
        fp=fopen(argv[i],"r");
        if(fp==NULL)
        {
            printf("ファイルが開けません\n");
            return -1;
        }

        char c;
        while (fscanf(fp,"%c",&c)!=EOF)
        {
            if('a'<=c&&c<='z')
            {
                printf("%c",kaidoku(c,'a',-3,'z'-'a'+1));
            }
            else if('A'<=c&&c<='Z')
            {
                printf("%c",kaidoku(c,'A',5,'Z'-'A'+1));
            }
            else if('0'<=c&&c<='9')
            {
                printf("%c",'9'-c+'0');
            }
            else
            {
                printf("%c",c);
            }
        }
        printf("\n");
        if(fclose(fp)==EOF)
        {
            return -1;
        }
    }
    return 0;
}

/*
./a.out sample.txt 
ABCDEFGHIJKLMNOPQRSTUFEDCB
abccdefghijklmnopqrstuvwxy
0123456789!”#$%&’()
*/