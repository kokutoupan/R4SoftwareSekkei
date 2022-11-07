#include <stdio.h>
#include <string.h>/* strcpyに必要*/
#include <stdlib.h>/* mallocに必要*/

struct node{
    char name[20];
    struct node* next;
};

struct node* add(char *, struct node*);
void show(struct node*);
void free_list(struct node*);

int main(void){
    char  data[20];
    struct node* head=NULL;
    /* 先頭ポインタをNULLに*/
    while ( scanf("%s", data) != EOF ) {
        head = add(data, head);
    }
    show(head);
    free_list(head);
    
    return 0;
}

/* ノードを追加する関数*/
struct node* add(char *d, struct node *h){
    struct node*p;
    p = malloc(sizeof(struct node));
    strcpy(p->name, d);
    p->next = h;
    return p;
}
/* リストを表示する関数*/
void show(struct node*p){
    while (p != NULL) {/* 次ポインタがNULLまで処理*/
        printf("%s -> ", p->name);
        p = p->next;
    }
    printf("NULL\n");
}

/* リストの要素を全開放する関数 */
void free_list(struct node* p){
    //printf("afea");
    while(p != NULL){
        struct node *tmp = p; 
        p = p->next;
        free(tmp);
    }
}
/*
fea  
21
feiji
feaijij
feaijij -> feiji -> 21 -> fea -> NULL
*/