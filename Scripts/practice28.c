//練習28

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
void *free_list(struct node *);

void insert(int n, char *data, struct node **head);
void insert3(int n, char *data, struct node **pHead);

void delete (int n, struct node **pHead);
void delete_name(char *str, struct node **pHead);

int main(void)
{
  char data[20];
  struct node *head = NULL;

  /* 先頭ポインタをNULLに*/
  while (scanf("%s", data) != EOF)
  {
    head = add(data, head);
  }
  show(head);

  head = free_list(head);
  show(head);

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
void *free_list(struct node *p)
{
  // printf("afea");
  while (p != NULL)
  {
    struct node *tmp = p;
    p = p->next;
    free(tmp);
  }
  return NULL;
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

      struct node *tmp = *pHead;
      *pHead = (*pHead)->next;
      free(tmp);
      return;
    }
    pHead = &(*pHead)->next;
  }

}

/*
aaa
bbb
ccc
ddd
ddd -> ccc -> bbb -> aaa -> NULL
NULL
*/
