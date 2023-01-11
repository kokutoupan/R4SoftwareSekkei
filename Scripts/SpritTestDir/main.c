//main.c

//--------------------------------------------
// ヘッダファイルのインクルード
//--------------------------------------------
#include <stdio.h>		// printf, scanf

#include "list.h"
//==============================================
// メイン関数
//==============================================
int main(void)
{
    int loop = 1;
    
    char data[20];
    struct node *head = NULL; /* 先頭ポインタをNULLに */

    do{
        printf("0) 終了\n");
        printf("1) 先頭にノードを追加\n");
        printf("2) 任意の位置にノードを挿入\n");
        printf("3) 指定のノードを削除\n");
        printf("4) 全ノードの削除\n");
        printf("5) 指定のデータのノードを削除\n");
        printf("6) データのソート\n");
        printf("\n何番の処理を行いますか？：");
        int select;
        scanf("%d",&select);

        int index;
        switch(select){
            case 0:
                loop = 0;
                break;
            case 1:
                printf("挿入するデータを入力してください:\n");
                scanf("%s",data);
                head = add(data,head);
                break;
            case 2: 
                printf("挿入するデータを入力してください:");
                scanf("%s",data);
                printf("挿入する場所を入力してください:");
                scanf("%d",&index);
                insert3(index,data,&head);
                break;
            case 3:
                printf("削除するノードの場所を入力してください:");
                scanf("%d",&index);
                delete2(index,&head);
                break;
            case 4:
                head = free_list(head);
                break;
            case 5:
                printf("削除するノードのデータを入力してください:");
                scanf("%s",data);
                delete_name(data,&head);
                break;
            case 6:
                sort(&head,cmpNode);
                break;
            default:
                select = 0;
                printf("0-5の番号で答えてください\n");
        }
        printf("\n");
        show(head);
        printf("\n");
    }while(loop);


    
    //-- 解放 ----------------------------
    head = free_list(head);
    show(head);     // 解放できたか表示

    return 0;
}

/* ソートの実装 実行結果は一部抜粋
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除
6) データのソート

何番の処理を行いますか？：1
挿入するデータを入力してください:
mazie
[0x4060c0] malloc

[head] -> mazie -> hoge -> bri -> 1fff -> [NULL]

0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のノードを削除
4) 全ノードの削除
5) 指定のデータのノードを削除
6) データのソート

何番の処理を行いますか？：6

[head] -> 1fff -> bri -> hoge -> mazie -> [NULL]
*/
