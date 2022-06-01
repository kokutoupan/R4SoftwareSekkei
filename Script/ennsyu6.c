#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


#define STARTRANGE '1'
#define ENDRANGE '9'
#define RANGESIZE (ENDRANGE-STARTRANGE)    


#define WORDSIZE 4

#define SWAP(type,A,B) {type tmp =A;A=B;B=tmp;}

int cmpnum(const void *n1,const void *n2)
{
    if(*(char*)n1 <*(char*)n2)
    {
        return -1;
    }
    else if(*(char*)n1>*(char*)n2)
    {
        return 1;
    }
    else
        return 0;
}

void makeword(char* str)
{
    char seat[RANGESIZE];

    for(int i=0;i<RANGESIZE;i++)
    {
        seat[i]=i+STARTRANGE;
    }

    for(int i =0;i < RANGESIZE;i++)
    {
        int r=(rand()%(RANGESIZE-i))+i;
        SWAP(char,seat[i],seat[r])
    }

    for(int i =0;i<WORDSIZE;i++)
    {
        str[i]=seat[i];
    }
    str[WORDSIZE]='\0';
}

int checkword(const char* correct,const char* anser)
{
    char hitarray[WORDSIZE]={};
    char blowarray[WORDSIZE]={};

    int hit=0,blow=0;

    for(int i=0;i<WORDSIZE;i++)
    {
        if(correct[i]==anser[i])
        {
            hitarray[hit]=correct[i];
            hit++;
        }
        else
        {
            for(int j=0;j<WORDSIZE;j++)
            {
                if(anser[i]==correct[j])
                {
                    blowarray[blow]=correct[j];
                    blow++;
                }
               
            }
        }
    }

    if(hit==4)
    {
        printf("BINGO!\n");
        return 0;
    }

    /*
    for(int i=0;i<WORDSIZE;i++)
    {
        printf("%c ",correct[i]);
    }
    */

    printf("HIT:%d BLOW:%d         ",hit,blow);

    if(hit !=0)
    {
        qsort(&hitarray[0],hit,sizeof(char),cmpnum);

        for(int i=0;i<hit;i++)
        {

           if(i == 0)
           {
               printf("%c",hitarray[i]);
           }
           else
           {
               printf(",%c",hitarray[i]);
           }
        }
        printf("がHIT");
    }
    else if(blow)
    {
        qsort(&blowarray[0],blow,sizeof(char),cmpnum);

        for(int i=0;i<blow;i++)
        {

           if(i == 0)
           {
               printf("%c",blowarray[i]);
           }
           else
           {
               printf(",%c",blowarray[i]);
           }
        }
        printf("がBLOW");
        
    }

    if(hit&&blow)
    {
        qsort(&blowarray[0],blow,sizeof(char),cmpnum);

        for(int i=0;i<blow;i++)
        {
            printf(",%c",blowarray[i]);
        }
        printf("がBLOW");
    }


    printf("\n");
    return 1;

}

int main(void)
{
    char word[WORDSIZE+1];

    srand((unsigned int)time(NULL));

    makeword(word);
    
    //printf("%s\n",word);　//正解

    char ans[WORDSIZE+1];
    int count =0;
    do{
        count++;
        printf("%d回目 = ",count);
        scanf("%s",&ans[0]);        
    }while(checkword(&word[0],&ans[0]));
}

/*
1回目 = 1234  
HIT:1 BLOW:1         3がHIT,4がBLOW
2回目 = 4536
HIT:1 BLOW:1         3がHIT,4がBLOW
3回目 = 7483
HIT:1 BLOW:3         4がHIT,3,7,8がBLOW
4回目 = 8437
BINGO!
*/