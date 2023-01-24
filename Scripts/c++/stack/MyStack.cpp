#include "MyStack.hpp"

#include <iostream>
#include <algorithm>


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

bool MyStack::Pop(POINT& out)
{
    if(this->IsEmpty()){
        return false;
    }
    head--;
    size--;
    out = *head;
    return true;
}

bool MyStack::Push(const POINT &_pos)
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
    return true;
}

bool MyStack::IsEmpty() const{
    return size ? false:true;
}
bool MyStack::IsFull() const{
    return capacity_last == head;
}

void MyStack::Show() const{
    POINT* i = head -1;
    std::cout << "\n";
    while (i >= data)
    {
        std::cout << "|"<< *i << "|\n";
        i--;
    }
    std::cout << "-------------------------------\n";
    
}
