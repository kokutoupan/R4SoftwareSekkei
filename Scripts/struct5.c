//練習29

#include <stdio.h>
#include <string.h>/* strcpyに必要*/
#include <stdlib.h>/* mallocに必要*/
#include <string.h>

struct node
{
    char name[20];
    struct node *next;
};

struct node *add(char *, struct node *);
void show(struct node *);
void free_list(struct node *);

void insert(int n, char *data, struct node **head);
void insert3(int n, char *data, struct node **pHead);

void delete (int n, struct node **pHead);
void delete_name(char *str, struct node **pHead);

int main(void)
{
    char data[20];
    struct node *head = NULL;
    int n;
    char c;
    int stdinFlag = stdin->_flags;

    // printf("%x\n",stdin->_flags);
    /* 先頭ポインタをNULLに*/
    while (scanf("%s", data) != EOF)
    {
        stdinFlag = stdin->_flags;
        head = add(data, head);
        // printf("%x\n",stdin->_flags);
    }
    show(head);
    // fflush(stdin);
    // getchar();
    // while(getchar()!= 1);
    // fscanf(stdin,"%s",data);
    // while (c != '\n') c = getchar();
    stdin->_flags = stdinFlag; //これでctrl-Dを押す前のstdinのフラグを上書きする
    // printf("%x",stdin->_flags);

    // printf("挿入するデータ: ");
    // scanf("%s", data);

    // printf("何番目の後に: ");
    // scanf("%d", &n);
    // insert3(n, data, &head); /* ノードの挿入*/
    // show(head);              /* 挿入後のノードの表示*/

    // /* 要素の削除*/
    // printf("何番目を削除しますか\n");
    // scanf("%d", &n);
    // delete (n, &head);
    // show(head);

    printf("どのデータを削除しますか\n");
    scanf("%s",data);
    delete_name(data,&head);
    show(head);

    free_list(head);

    return 0;
}

/* ノードを追加する関数*/
struct node *add(char *d, struct node *h)
{
    struct node *p;
    p = malloc(sizeof(struct node));
    strcpy(p->name, d);
    p->next = h;
    return p;
}

/* リストを表示する関数*/
void show(struct node *p)
{
    while (p != NULL)
    { /* 次ポインタがNULLまで処理*/
        printf("%s -> ", p->name);
        p = p->next;
    }
    printf("NULL\n");
}

/* リストを全開放 */
void free_list(struct node *p)
{
    // printf("afea");
    while (p != NULL)
    {
        struct node *tmp = p;
        p = p->next;
        free(tmp);
    }
}

/* リストにノードを挿入する関数*/
void insert(int n, char *data, struct node **head)
{
    struct node *p = *head;
    int i;
    struct node *x; /* 挿入するノードの準備*/
    x = malloc(sizeof(struct node));
    strcpy(x->name, data);

    if (n == 0)
    {
        *head = x;
        x->next = p;
        return;
    }
    /* 挿入する位置の手前までノードをたどる*/
    for (i = 0; i < n - 1; i++)
        p = p->next; /* ノードの付け替え*/
    x->next = p->next;
    p->next = x;
}

void insert3(int n, char *data, struct node **pHead)
{
    for (int i = 0; i < n; i++)
    {
        pHead = &(*pHead)->next;
    }
    *pHead = add(data, *pHead);
}

/* n番目の要素を削除する関数*/
void delete (int n, struct node **pHead)
{
    for (int i = 0; i < n - 1; ++i)
    {
        pHead = &(*pHead)->next;
    }
    struct node *tmp = *pHead;
    *pHead = (*pHead)->next;
    free(tmp);
}

void delete_name(char *str, struct node **pHead)
{
    while (*pHead != NULL)
    {
        if (!strcmp(str, (*pHead)->name))
        {
            break;
        }
        pHead = &(*pHead)->next;
    }

    struct node *tmp = *pHead;
    *pHead = (*pHead)->next;
    free(tmp);
}