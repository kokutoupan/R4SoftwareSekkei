#include <stdio.h>
#include <stdlib.h>

#define PATHSIZE (21)

int sugoloku(int posithion,int dise,int gool,const int * masu)
{
    int next=posithion+dise;

    //printf("%d\n",next);

    if(next>=gool)
    {
        return next;
    }

    next+=masu[next-1];

    if(next <=0)
    {
        next=1;
    }

    return next;
}

int main(void)
{
    FILE *fp;
    char filepath[PATHSIZE];
    
    printf("入力ファイル = ");
    scanf("%s",&filepath[0]);
    
    fp=fopen(filepath,"r");
    if(fp==NULL)
    {
        printf("ファイルが開けません\n");
        return -1;
    }

    int Nmasu,Msaikoro;
    if(fscanf(fp,"%d %d",&Nmasu,&Msaikoro)==EOF)
    {
        printf("erro");
        return -1;
    }

    int *masudata =(int*)malloc(sizeof(int)*Nmasu);
    int *daisudata=(int*)malloc(sizeof(int) * Msaikoro);
    if(masudata==NULL||daisudata==NULL)
    {
        printf("メモリが確保できませんでした\n");
        return 1;
    }

    //dateの読み込み
    for(int i=0;i<Nmasu;i++)
    {
        fscanf(fp,"%d",masudata+i);
    }
    for(int i=0;i<Msaikoro;i++)
    {
        fscanf(fp,"%d",daisudata+i);
    }

    if(fclose(fp)==EOF)
    {
        printf("ファイルが閉じれませんでした\n");
        return -1;
    }

    int turn =1,now=1;

    while ((now=sugoloku(now,daisudata[turn -1],Nmasu,masudata))<Nmasu)
    {
        turn++;
        //printf("%d %d\n",turn,now);
    }
    
    printf("%d回目でゴール\n",turn);

    return 0;
}

/*
入力ファイル = 07data00.txt
5回目でゴール

入力ファイル = 07data01.txt
14回目でゴール

入力ファイル = 07data02.txt
5回目でゴール

入力ファイル = 07data03.txt
400回目でゴール

入力ファイル = 07data04.txt
156回目でゴール

入力ファイル = 07data05.txt
238回目でゴール
*/