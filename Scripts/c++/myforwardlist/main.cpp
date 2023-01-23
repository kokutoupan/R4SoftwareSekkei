//main.cpp

#include <iostream>

#include "SingleList.hpp"


int main(){
    bool loop = true;
    
    char data[20];
    SingleList A;

    do{
        std::cout << "0) 終了\n";
        std::cout << "1) 先頭にノードを追加\n";
        std::cout << "2) 任意の位置にノードを挿入\n";
        std::cout << "3) 指定のデータのノードを削除\n";
        std::cout << "4) ノード数の表示\n";
        std::cout << "5) 全ノードの削除\n";

        std::cout << "\n何番の処理を行いますか？：";
        int select;
        std::cin >> select;

        int index;
        switch(select){
            case 0:
                loop = 0;
                break;
            case 1:
                std::cout << "挿入するデータを入力してください:\n";
                std::cin >> data;
                A.Add(data);
                
                break;
            case 2: 
                std::cout << "挿入するデータを入力してください:";
                std::cin >> data;
                std::cout << "挿入する場所を入力してください:";
                std::cin >> index;
                A.Insert(index,data);
                break;
            case 3:
                std::cout << "削除するノードの場所を入力してください:";
                std::cin >> index;
                A.Delete(index);
                break;
            case 4:
                std::cout << "ノード数" << A.GetNumNodes() << "\n";
                break;
            case 5:
                A.Clear();
                break;
            default:
                select = 0;
                printf("0-5の番号で答えてください\n");
        }
        std::cout << "\n";
        A.Show();
        std::cout << "\n";
    }while(loop);


    
    //-- 解放 ----------------------------
    A.Clear();

}


/*
make SingleList
0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のデータのノードを削除
4) ノード数の表示
5) 全ノードの削除

何番の処理を行いますか？：1
挿入するデータを入力してください:
aaa
new node[0x7ffda6698698]

aaa

0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のデータのノードを削除
4) ノード数の表示
5) 全ノードの削除

何番の処理を行いますか？：1
挿入するデータを入力してください:
bbb
new node[0x7ffda6698698]

bbb
aaa

0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のデータのノードを削除
4) ノード数の表示
5) 全ノードの削除

何番の処理を行いますか？：2
挿入するデータを入力してください:1
挿入する場所を入力してください:1  
new node[0x7ffda66986b8]

bbb
1
aaa

0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のデータのノードを削除
4) ノード数の表示
5) 全ノードの削除

何番の処理を行いますか？：3
削除するノードの場所を入力してください:2

bbb
aaa

0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のデータのノードを削除
4) ノード数の表示
5) 全ノードの削除

何番の処理を行いますか？：4
ノード数2

bbb
aaa

0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のデータのノードを削除
4) ノード数の表示
5) 全ノードの削除

何番の処理を行いますか？：5


0) 終了
1) 先頭にノードを追加
2) 任意の位置にノードを挿入
3) 指定のデータのノードを削除
4) ノード数の表示
5) 全ノードの削除

何番の処理を行いますか？：0


delete SingleList

*/