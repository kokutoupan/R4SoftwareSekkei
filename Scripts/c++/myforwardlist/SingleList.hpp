//SingleList.hpp

#ifndef SINGLELIST_HPP_INCLUDEGERDE
#define SINGLELIST_HPP_INCLUDEGERDE

struct node {
    char name[20];          // データ部
    struct node *next;      // ポインタ部
};

class SingleList{
    node *m_head; //head
    int m_nodes;  //ノードの数
    
public:
    SingleList();
    ~SingleList();

    void Add(char *name);
    void Show();

    void Insert(int n,char *name);
    void Delete(int n);

    void Clear();

    int GetNumNodes(){
        return m_nodes;
    }
};

#endif
