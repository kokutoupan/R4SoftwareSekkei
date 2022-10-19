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
    char* name;
    char* address;
    char* phone;
};

char* mystrdup(const char* str){
    char* ans = (char *)malloc((1 + strlen(str))*sizeof(char));
    memcpy(ans,str,(1 + strlen(str))*sizeof(char));
    return ans;
}

void freemember(struct p_person* p){
    free(p->name);
    free(p->address);
    free(p->phone);
}

void copyMember(struct p_person* p1,const struct p_person* p2){
    p1->name = mystrdup(p2->name);
    p1->address = mystrdup(p2->address);
    p1->phone = mystrdup(p2->phone);
}

void printPerson(struct p_person* p){
    printf("%s\n",p->name);
    printf("%s\n",p->address);
    printf("%s\n",p->phone);
}

int main(void){
    printf("練習23\n");
    printf("サイズ %ld : %ld\n",sizeof(struct a_person),sizeof(struct p_person));
    {//練習24
        printf("\n練習24\n");
        struct p_person p;
    
        p.name = mystrdup("aoki");
        p.address = mystrdup("mityo");
        p.phone = mystrdup("090XXXX");
        printPerson(&p);
        freemember(&p);
    }
    {//練習25
        printf("\n練習25\n");
        struct p_person p = { "aoki", "mitoyo", "090XXXX" };
        struct p_person q;
        copyMember(&q,&p);
        printPerson(&q);

        freemember(&q);
    }
    
    return 0;
}

/*
練習23
サイズ 115 : 24

練習24
aoki
mityo
090XXXX

練習25
aoki
mitoyo
090XXXX
*/