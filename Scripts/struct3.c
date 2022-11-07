#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct a_person
{
    char name[20];
    char address[80];
    char phone[15];
};

struct p_person
{
    char *name;
    char *address;
    char *phone;
};

char *mystrdup(const char *str)
{
    char *ans = (char *)malloc((1 + strlen(str)) * sizeof(char));
    memcpy(ans, str, (1 + strlen(str)) * sizeof(char));
    return ans;
}

void freemember(struct p_person *p)
{
    free(p->name);
    free(p->address);
    free(p->phone);
}

void structfree(struct p_person *p, const int n)
{
    for (int i = 0; i < n; i++)
    {
        freemember(p + i);
    }
    free(p);
}

void copyMember(struct p_person *p1, const struct p_person *p2)
{
    p1->name = mystrdup(p2->name);
    p1->address = mystrdup(p2->address);
    p1->phone = mystrdup(p2->phone);
}

void printPerson(struct p_person *p)
{
    printf("%s\n", p->name);
    printf("%s\n", p->address);
    printf("%s\n", p->phone);
}

int main(void)
{
    { //練習26
        printf("練習26\n");
        struct p_person p;

        p.name = mystrdup("aoki");
        p.address = mystrdup("mityo");
        p.phone = mystrdup("090XXXX");
        printPerson(&p);
        freemember(&p);
    }
    { //練習27
        printf("\n練習27\n");
        struct p_person *p;
        int n = 5;
        p = malloc(sizeof(struct p_person) * n);
        p->name = mystrdup("aoki");
        p->address = mystrdup("mitoyo");
        p->phone = mystrdup("090XXXX");

        for (int i = 1; i < n; ++i)
        {
            (p + i)->name = mystrdup("hoka");
            (p + i)->address = mystrdup("hokaAddress");
            (p + i)->phone = mystrdup("hokaPhone");
        }
        printPerson(p);
        for(int i=1;i < n;++i){
            printPerson(p+i);
        }
        structfree(p, n); /* n人分のメモリ解放*/
    }

    return 0;
}

/*
練習26
aoki
mityo
090XXXX

練習27
aoki
mitoyo
090XXXX
hoka
hokaAddress
hokaPhone
hoka
hokaAddress
hokaPhone
hoka
hokaAddress
hokaPhone
hoka
hokaAddress
hokaPhone
*/