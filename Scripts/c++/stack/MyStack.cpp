#include "MyStack.hpp"

#include <iostream>
#include <algorithm>

template <class Char> // 出力ストリーム
std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const POINT& v)
{
    return os << Char('(') << v.x << Char(',') << v.y << Char(')');
}


MyStack::MyStack()
{
    size = 0;
    capacity_size = 1;
    data = new POINT[capacity_size];
    head = data;
    capacity_last = data + capacity_size;
}

MyStack::~MyStack()
{
    delete[] data;
}

POINT MyStack::Pop()
{
    if(this->IsEmpty()){
        //
    }
    head--;
    size--;
    std::cout << "(" << head->x << ',' << head->y << ")\n";
    return *head;
}

void MyStack::Push(POINT &_pos)
{
    //std::cout << "aaa" << std::endl;
    if (this->IsFull())
    {
        POINT *tmp = data;
        capacity_size *= 2;

        std::cout << "再確保 size:" << capacity_size << "\n";
        data = new POINT[capacity_size];
        std::copy(tmp, head, data);

        head = data + size;
        capacity_last = data + capacity_size;

        // std::cout << "(" << data->x << ',' << data->y << ")\n";
        delete[] tmp;
    }

    *head = _pos;
    head++;
    size++;
    return;
}

bool MyStack::IsEmpty(){
    return size ? 1:0;
}
bool MyStack::IsFull(){
    return capacity_last == head;
}

void MyStack::Show(){
    POINT* i = head -1;
    while (i >= data)
    {
        std::cout << *i;
        i--;
    }
    std::cout << "\n";
    
}