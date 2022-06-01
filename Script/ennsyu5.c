#include <stdio.h>
#include <stdlib.h>

int koisi(int* wanofishi,int *temoto)
{
    if(*wanofishi >0)
    {
        *temoto +=1;
        *(wanofishi)=*(wanofishi)-1;

        if(*wanofishi==0)
        {
            return 1;//空になったとき
        }
        return 0;
    }
    else
    {
        *wanofishi+=*temoto;
        *temoto=0;
        return 0;
    }
}

int main (void)
{
    int n,p;
    printf("n = ");
    scanf("%d",&n);
    printf("p = ");
    scanf("%d",&p);

    int *player=(int*)calloc(sizeof(int),n);
    if(player==NULL)
    {
        return 1;
    }
    int own=p;
    int win=-1;
    int cnt=0;

    do
    {
        for(int i=0;i<n;i++)
        {
            cnt++;
            win=-1;
            if(koisi(&own,&player[i])==1)
            {
               if(player[i]==p)
               {
                   win=i;
               }
            }
            if(win!=-1)
            {
                break;
            }
       }
    }while (win==-1);
    

    printf("%d番目が勝者\n%dステップ目で終了\n",win,cnt);

    return 0;
}

/*
n = 3
p = 3
0番目が勝者
13ステップ目で終了

n = 3
p = 50
1番目が勝者
9701ステップ目で終了

n = 10
p = 29
5番目が勝者
929006ステップ目で終了

n = 31
p = 32
30番目が勝者
992ステップ目で終了

n = 50
p = 2
1番目が勝者
52ステップ目で終了

n = 50
p = 50
13番目が勝者
3214ステップ目で終了
*/