#include <stdio.h>

int main(void)
{
    char a = 'A';
    int b = 100;
    double c = 3.14;
    char *pa = &a;
    int *pb =&b;
    double *pc =&c;

    printf("%c\n",*pa);
    printf("%d\n",*pb);
    printf("%lf\n",*pc);

    return 0;
}

/*
A
100
3.140000
*/