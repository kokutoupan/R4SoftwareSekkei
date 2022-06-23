#include <stdio.h>

int main(void) {
    char s[100] ="abcdef";
    //char *p = &3[s];
    char *p = s+3;

    scanf("%s",p);
    printf("%s\n",s);
    
    return 0;
}

/*
DEF
abcDEF
*/