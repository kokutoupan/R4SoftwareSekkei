//list.h

#ifndef INCLUDED_LIST_H_
#define INCLUDED_LIST_H_

//--------------------------------------------
// 構造体の定義
//--------------------------------------------
typedef struct node {
    char name[20];          // データ部
    struct node *next;      // ポインタ部
} NODE;

//--------------------------------------------
// 関数プロトタイプ宣言
//--------------------------------------------
struct node *add(char *, struct node *);
void show(struct node *);
struct node *free_list(struct node *p);
void insert(int n, char *data, struct node *p);
void insert2(int n, char *data, struct node **pHead);
void insert3(int n, char *data, struct node **pHead);
void delete1(int n, struct node **pHead);
void delete2(int n, struct node **pHead);
void delete_name(char *s, struct node **pHead);


int countNode(struct node* p);
int cmpNode(const void *n1,const void *n2);
void sort(struct node **pHead,int (* cmpFunc)(const void * n1, const void * n2));

#endif
