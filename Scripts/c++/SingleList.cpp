//SingleList.cpp
//#include <stdio.h>
#include <iostream>

#include "SingleList.hpp"

SingleList::SingleList(){
    m_head = nullptr;
    m_nodes = 0;
    std::cout << "make SingleList";
}

SingleList::~SingleList(){
    std::cout << "delete SingleList";
}

void SingleList::Add(char* data){
    Insert(0,data);
}

void SingleList::Show(){
    node *np = m_head;

    while(m_head != nullptr){
        std::cout << np->data << "\n";
        np = np->next;
    }
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
}

void SingleList::Clear(){
    while(m_nodes > 0){
        SingleList::Delete(1);
    }
}
