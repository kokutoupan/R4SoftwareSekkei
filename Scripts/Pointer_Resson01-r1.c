#include <stdio.h>

void rei3(void);
void rei4(void);
void rei5(void);

int main(void)
{
    char a;
    int b;
    float c;
    double d;

    printf("例１\n");
    printf("a : %u byte\n", sizeof(a));
    printf("b : %u byte\n", sizeof(b));
    printf("c : %u byte\n", sizeof(c));
    printf("d : %u byte\n", sizeof(d));

    printf("\n例２\n");
    printf("char          %u byte\n", sizeof(char));
    printf("int           %u byte\n", sizeof(int));
    printf("float         %u byte\n", sizeof(float));
    printf("double        %u byte\n", sizeof(double));
    printf("short int     %u byte\n", sizeof(short int));
    printf("long int      %u byte\n", sizeof(long int));
    printf("unsigned int  %u byte\n", sizeof(unsigned int));
    printf("long double   %u byte\n", sizeof(long double));
    printf("long long int %u byte\n", sizeof(long long int));

    rei3();
    rei4();
    rei5();

    return 0;
}

void rei3(void)
{
    printf("\n例３\n");

    char a[10];
    int b[5];
    double c[8];

    printf("a: %u byte\n", sizeof(a));
    printf("b: %u byte\n", sizeof(b));
    printf("c: %u byte\n", sizeof(c));

    printf("a[0]: %u byte\n", sizeof(a[0]));
    printf("b[2]: %u byte\n", sizeof(b[2]));
    printf("c[5]: %u byte\n", sizeof(c[5]));
}

void rei4(void)
{
    printf("\n例4\n");
    
    int d[3][4];

    printf("d:       %u byte\n", sizeof(d));
    printf("d[1]:    %u byte\n", sizeof(d[1]));
    printf("d[1][3]: %u byte\n", sizeof(d[1][3]));
}

void rei5(void)
{
    printf("\n例5\n");

    printf("100        %u byte\n",sizeof(100));
    printf("100L       %u byte\n",sizeof(100L));
    printf("3.14       %u byte\n",sizeof(3.14));
    printf("3.14f      %u byte\n",sizeof(3.14f));
    printf("'A'        %u byte\n",sizeof('A'));
    printf("\"abcdef\"   %u byte\n",sizeof("abcdef"));
}

/*
例１
a : 1 byte
b : 4 byte
c : 4 byte
d : 8 byte

例２
char          1 byte
int           4 byte
float         4 byte
double        8 byte
short int     2 byte
long int      8 byte
unsigned int  4 byte
long double   16 byte
long long int 8 byte

例３
a: 10 byte
b: 20 byte
c: 64 byte
a[0]: 1 byte
b[2]: 4 byte
c[5]: 8 byte

例4
d:       48 byte
d[1]:    16 byte
d[1][3]: 4 byte

例5
100        4 byte
100L       8 byte
3.14       8 byte
3.14f      4 byte
'A'        4 byte
"abcdef"   7 byte
*/