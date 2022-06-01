#include <stdio.h>

#define PATHSIZE (21)

void bigThree(int* arry,int num)
{
    for(int i=0;i<3;i++)
    {
        if(arry[i]<num)
        {
            int tmp=arry[i];
            arry[i]=num;
            num=tmp;
        }
    }
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

    int tmp;
    int Wdai[3]={},Kdai[3]={};

    for(int i=0;i<10;i++)
    {
        fscanf(fp,"%d",&tmp);
        bigThree(Wdai,tmp);
    }

    for(int i=0;i<10;i++)
    {
        fscanf(fp,"%d",&tmp);
        bigThree(Kdai,tmp);
    }

    int Wsum=0,Ksum=0;
    for(int i=0;i<3;i++)
    {
        Wsum+=Wdai[i];
        Ksum+=Kdai[i];
    }

    printf("W大学 = %d点\n",Wsum);
    printf("K大学 = %d点\n",Ksum);

    if( Wsum>Ksum)
    {
        printf("W大学の勝利!!\n");
    }
    else if(Wsum <Ksum)
    {
        printf("K大学の勝利!!\n");
    }
    else
    {
        printf("引き分けです\n");
    }
    
    return 0;
}

/*
入力ファイル = 08data02.txt
W大学 = 240点
K大学 = 250点
K大学の勝利!!

入力ファイル = 08data01.txt
W大学 = 66点
K大学 = 61点
W大学の勝利!!

入力ファイル = 08data03.txt
W大学 = 283点
K大学 = 293点
K大学の勝利!!

入力ファイル = 08data04.txt
W大学 = 259点
K大学 = 259点
引き分けです

入力ファイル = 08data05.txt
W大学 = 259点
K大学 = 224点
W大学の勝利!!
*/