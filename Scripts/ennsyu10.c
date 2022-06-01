#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include<stdbool.h>

#define PATHSIZE (256)

bool HitWord(char* str,int strsize,char* word,int wordsize)
{
    bool flag;
    while(strsize >= wordsize)
    {
        flag =true;
        for(int i=0;i<wordsize;i++)
        {
            if(str[i]!=word[i])
            {
                flag =false;
                break;
            }
        }
        if(flag)
        {
            return true;
        }
        str++;
        strsize--;
    }

    return false;
}

int main(void)
{
    FILE *fp;
    char path[PATHSIZE];
    
    printf("入力ファイル = ");
    scanf("%[^\n]",&path[0]);

    fp = fopen(path,"r");
    if(fp==NULL)
    {
        printf("ファイルが開けません\n");
        return -1;
    }

    char str1[4001],str2[4001];
    char *ptr1 =str1,*ptr2=str2;
    int length1,length2;

    fscanf(fp,"%s",ptr1);
    fscanf(fp,"%s",ptr2);

    if(fclose(fp)==EOF)
        return -1;

    //printf("%s\n",ptr1);
    //printf("%s",ptr2);
    //printf("a\n");

    length1=strlen(ptr1);
    length2=strlen(ptr2);

    if(length1 < length2)
    {
        char *tmp =ptr1;
        ptr1=ptr2;
        ptr2=tmp;
        int tmpsize=length1;
        length1 =length2;
        length2=tmpsize;
    }


    //printf("%s\n",ptr1);
    //printf("%s",ptr2);
    //printf("a\n");

    int limitword=0;
    char *wordptr =ptr2;
    do
    {
        if(HitWord(ptr1,length1,wordptr,limitword+1) )
        {
            limitword++;
            //wordptr = ptr2;
            //printf("%d\n",limitword);
        }
        else
            wordptr++;
    }while(!(wordptr+(limitword) >=ptr2 +length2));
    
    printf("最大長=%d文字\n",limitword);

    return 0;
}

/*
入力ファイル = 10data01.txt
最大長=5文字

入力ファイル = 10data02.txt
最大長=0文字

入力ファイル = 10data03.txt
最大長=12文字

入力ファイル = 10data04.txt
最大長=31文字

入力ファイル = 10data05.txt
最大長=719文字

入力ファイル = 10data06.txt
最大長=3995文字

入力ファイル = 10data07.txt
最大長=0文字
*/