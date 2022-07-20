//例１０
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int i, n;
    int *p = NULL;

    scanf("%d", &n);
    p = (int *)malloc(sizeof(int) * n);//なんでvoidなのにC++はエラー出るだー 
    if( p ==NULL && n != 0 )
    {
        printf("メモリが確保できません");
        return 1;
    }

    for(i = 0; i < n; i++) scanf("%d",p+i);

    for(i = 0; i< n ;i++) printf("[%d] %d\n", i, *(p+i));

    free(p);

    return 0;
}
