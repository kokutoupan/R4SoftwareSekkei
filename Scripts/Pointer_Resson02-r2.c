#include <stdio.h>
#include <math.h>

int main(void)
{
    int a;

    printf("&a  = %u byte\n", sizeof(&a));
    printf("%.0f byte\n", pow(16, sizeof(&a) * 2));
}

/*
&a  = 8 byte
18446744073709551616 byte
*/

/*
[ユーザ名 ~]$ free -h
               total        used        free      shared  buff/cache   available
Mem:           7.6Gi       3.2Gi       256Mi       1.1Gi       4.1Gi       2.9Gi
Swap:            9Gi        27Mi         9Gi
*/