//SingleList.hpp

#ifndef SINGLELIST_HPP_INCLUDEGERDE
#define SINGLELIST_HPP_INCLUDEGERDE

struct node{
    char *data;
    node* next;
};

class SingleList{
    node *m_head; //head
    int m_nodes;  //ノードの数
    
public:
    SingleList();
    ~SingleList();

    void Add(char *data);
    void Show();

    void Insert(int n,char *data);
    void Delete(int n);

    void Clear();
};

#endif
