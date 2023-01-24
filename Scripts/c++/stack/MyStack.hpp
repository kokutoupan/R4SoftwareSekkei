#ifndef MYSTACK_INCLUDEGARDE
#define MYSTACK_INCLUDEGARDE

#include <iostream>

struct POINT
{
    int x;
    int y;
    POINT() = default;
    POINT(int _x, int _y) : x(_x), y(_y) {}
};

template <class Char> // 出力ストリーム
inline std::basic_ostream<Char>& operator <<(std::basic_ostream<Char>& os, const POINT& v)
{
    return os << Char('(') << v.x << Char(',') << v.y << Char(')');
}

template <class T>
class MyStack
{
    T *data;
    T *head;

    T *capacity_last;

    int capacity_size;

public:
    int size;
    MyStack();
    ~MyStack();

    bool Pop(T& out);
    bool Push(const T& _pos);

    bool IsEmpty() const;
    bool IsFull() const;
    void Show() const;
};

template <class T>
bool MyStack<T>::Pop(T& out)
{
    if(this->IsEmpty()){
        return false;
    }
    head--;
    size--;
    out = *head;
    return true;
}


template <class T>
bool MyStack<T>::Push(const T &_pos)
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

template<class T>
MyStack<T>::MyStack()
{
    size = 0;
    capacity_size = 1;
    data = new POINT[capacity_size];
    head = data;
    capacity_last = data + capacity_size;
}

template<class T>
MyStack<T>::~MyStack()
{
    delete[] data;
}


template<class T>
bool MyStack<T>::IsEmpty() const{
    return size ? false:true;
}
template<class T>
bool MyStack<T>::IsFull() const{
    return capacity_last == head;
}

template<class T>
void MyStack<T>::Show() const{
    POINT* i = head -1;
    std::cout << "\n";
    while (i >= data)
    {
        std::cout << "|"<< *i << "|\n";
        i--;
    }
    std::cout << "-------------------------------\n";
    
}
#endif
