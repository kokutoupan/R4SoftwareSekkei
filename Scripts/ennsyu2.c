#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SWAP(type,A,B) {type tmp=A;A=B;B=tmp;}

/*
void move(int* buf1,int* buf2,int size)
{
    for(int i=0;i<size;i++)
    {
        *(buf1 +i)=*(buf2+i);
    }
}
*/

void shuffle(int *seet,int size)
{
    for(int i=size;i>1;i--)
    {
        int r=rand()%(i);
        SWAP(int,seet[i-1],seet[r])
    }
}
int main(void)
{
    int n;
    int *seet;
    srand((unsigned int)time(NULL));

    printf("クラス人数 = ");
    scanf("%d",&n);
    
    seet=malloc(sizeof(int)*n);
    if(seet==NULL)
    {
        return 1;
    }

    for(int i =0;i<n;i++)
    {
        *(seet+i)=i+1;
    }

    shuffle(seet,n);
    for(int i=0;i<n;i++)
    {
        printf("%d\n",*(seet+i));
    }
/*
    for(int i=0;i<n;i++)
    {
        int r=rand()%(n-i);
        printf("%d\n",*(seet+r));

        move(seet+r,seet+r+1,(n-i)-r-1);
    }
*/

    free(seet);
    return 0;
}

/*
クラス人数 = 40
18
31
24
23
13
37
29
40
6
21
17
30
11
10
8
2
4
33
39
35
16
19
22
9
1
34
3
14
32
26
20
5
38
28
15
7
36
12
27
25
*/