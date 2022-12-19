//list.c

//--------------------------------------------
// ヘッダファイルのインクルード
//--------------------------------------------
#include <stdio.h>		// printf, scanf
#include <string.h>		// strcpy, strcmp
#include <stdlib.h>		// malloc,free 

#include "list.h"

//==============================================
// 特定のデータ部をもつノードを削除
//==============================================
void delete_name(char *s, struct node **pHead)
{
    struct node *tmp;

    while (*pHead != NULL) {

        // データ部が所定の文字列に一致していれば削除
        if ( strcmp((*pHead)->name, s) == 0 ) {
            tmp = (*pHead)->next;
            free(*pHead);
            *pHead = tmp;
            //return;				// 関数を抜ける	
        }
        else
            pHead = &((*pHead)->next);
    }
}

//==============================================
//	delete: 指定のノードを削除 (場合分け版)
//==============================================
void delete1(int n, struct node **pHead)
{
    int i;
    struct node *p;
    struct node *tmp;

    p = *pHead;

    if (n>1) {
        for (i=0; i<n-2; i++)
            p = p->next;

        tmp = p->next->next;
        free(p->next);
        printf("[%p] free\n", p->next);
        p->next = tmp;
    }

    // 1番目のノードを削除するとき
    else {
        tmp = (*pHead)->next;
        free(*pHead);
        *pHead = tmp;
    }
}

//==============================================
//	delete: 指定のノードを削除 (ver.2)
//==============================================
void delete2(int n, struct node **pHead)
{	
    int i;
    struct node *tmp;

    for (i=0; i<n-1; i++)
        pHead = &((*pHead)->next);

    tmp = (*pHead)->next;
    free(*pHead);
    *pHead = tmp;
}

//==============================================
// free_list: 全てのノードを解放
//==============================================
struct node *free_list(struct node *p)
{
    struct node *q;

    while (p != NULL) {
        q = p->next;
        free(p);
        printf("[%p] free\n", p);
        p = q;
    }

    return NULL;
}

//==============================================
// add: ノードを追加する関数 
//==============================================
struct node *add(char *d, struct node *h)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    printf("[%p] malloc\n", p);

    strcpy(p->name, d);
    p->next = h;
    return p;
}

//==============================================
// show: リストを表示する関数 
//==============================================
void show(struct node *p)
{
    printf("[head] -> ");
    // 次ポインタがNULLまで処理 
    while (p != NULL) { 	
        printf("%s -> ", p->name);
        p = p->next;
    }

    printf("[NULL]\n");
}


//==============================================
//  insert: 任意の位置にノードを挿入
//     n: 挿入位置
//	data: 挿入するノードに持たせる文字列
//	   p: 先頭ノードのアドレス(=head)
//==============================================
void insert(int n, char *data, struct node *p)
{
    int i;
    struct node *x;

    // 挿入するノードの準備 
    x = malloc(sizeof(struct node));
    strcpy(x->name, data);

    // 挿入する位置の手前までノードをたどる
    for ( i=0; i<n-1; i++) 
        p = p->next;

    // ノードの付け替え
    x->next = p->next;
    p->next = x;
}

//==============================================
// insert: 任意の位置にノードを挿入(0挿入可,場合分け)
//==============================================
void insert2(int n, char *data, struct node **pHead)
{
    struct node *x;
    struct node *p = *pHead;	// p は head と同じアドレス

    // 挿入位置が0のとき→> 関数addを利用
    if (n==0) {
        *pHead = add(data, p);
    }

    // 挿入位置>0のとき→> テキストのinsertと同様
    else {
        insert(n, data, p);
    }
}

//==============================================
// insert: 任意の位置にノードを挿入(改良版)
//==============================================
void insert3(int n, char *data, struct node **pHead)
{
    // pHeadを適切な位置に遷移
    int i;
    for (i=0; i<n; i++)
        pHead = &((*pHead)->next);

    // ノードを追加
    *pHead = add(data, *pHead);
}


int cmpNode(const void *n1,const void *n2){
    return strcmp((const struct node*)n1->name,(const struct node*)n2->name);
}
void sort(struct node **pHead,int (* cmpFunc)(const void * n1, const void * n2)){

}
