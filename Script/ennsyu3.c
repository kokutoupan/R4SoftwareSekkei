#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void)
{
    char path[256];
    int ninnzu;

    printf("入力ファイル = ");
    scanf("%[^\n]",&path);
    //printf("%s",path);
    
    FILE *fp=fopen(path,"r");
    if(fp==NULL)
    {
        printf("ファイルが読み込めません\n");
        return 1;
    }


    if(feof(fp)==0)
    {
        fscanf(fp,"%d",&ninnzu);
    }

    bool* call =(bool*)calloc(ninnzu,sizeof(bool));
    int temp,line=0;
    while (fscanf(fp,"%d",&temp)!=EOF)
    {
        call[temp-1]=true;
        line ++;
    }
    
    if(fclose(fp)==EOF)
    {
        return 1;
    }

    /*
    int cnt =0;
    for(int i=0;i<ninnzu;i++)
    {
        if(call[i]==false)
        {
            cnt++;
        }
    }
    */
    int cnt =ninnzu -line;
    if( cnt <=0)
    {
        printf("全員が提出しています\n");
        return 0;
    }

    printf("以下の%d名が未提出です\n",cnt);
    for(int i=0;i<ninnzu;i++)
    {
        if(call[i]==false)
            printf("%2d番\n",i+1);
    }

    free(call);
    return 0;
}

/*
入力ファイル = report1.txt
全員が提出しています
*/

/*
入力ファイル = report1.txt
以下の1名が未提出です
20番
*/