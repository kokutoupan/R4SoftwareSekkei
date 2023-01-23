//SingleList.cpp
//#include <stdio.h>
#include <string.h>

#include <iostream>

#include "SingleList.hpp"

SingleList::SingleList(){
    m_head = nullptr;
    m_nodes = 0;
    std::cout << "make SingleList\n";
}

SingleList::~SingleList(){
    std::cout << "delete SingleList\n";
}

void SingleList::Add(char* name){
    Insert(0,name);
}

void SingleList::Show(){
    node *np = m_head;

    while(np != nullptr){
        std::cout << np->name << "\n";
        np = np->next;
    }
}

void SingleList::Insert(int n, char* name){
    node **pHead  = &m_head;
    for (int i=0; i<n; i++)
        pHead = &((*pHead)->next);

    // ノードを追加
    node *p = new node;
    std::cout << "new node[" << &p <<"]\n";
    strcpy(p->name,name);
    
    p->next = *pHead;
    *pHead = p;

    this->m_nodes++;
}

void SingleList::Delete(int n){
    if(n < 1 || n > this->m_nodes)
        return;

    node *tmp;
    node **pHead = &m_head;

    for (int i=0; i<n-1; i++)
        pHead = &((*pHead)->next);

    tmp = (*pHead)->next;
    free(*pHead);
    *pHead = tmp;

    this->m_nodes--;
}

void SingleList::Clear(){
    while(m_nodes > 0){
        SingleList::Delete(1);
    }
}
