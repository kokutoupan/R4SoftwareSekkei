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

template <class Char> // POINTの出力演算子のオーバーロード
inline std::basic_ostream<Char> &operator<<(std::basic_ostream<Char> &os, const POINT &v)
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
    int mSize;

public:
    MyStack();
    MyStack(const unsigned int n);
    ~MyStack();

    bool Pop(T &out);
    T Pop(bool &ret);
    bool Push(const T &_pos);

    bool IsEmpty() const;
    bool IsFull() const;
    void Show() const;

    int size() const;

    int remain() const;
};

//-----------------------------------------------------------------------------
// 実装
//-----------------------------------------------------------------------------

template <class T>
MyStack<T>::MyStack()
{
    mSize = 0;
    capacity_size = 1;
    data = new T[capacity_size];
    head = data;
    capacity_last = data + capacity_size;
}

template <class T>
MyStack<T>::MyStack(const unsigned int n)
{
    mSize = 0;
    capacity_size = n;
    data = new T[capacity_size];
    head = data;
    capacity_last = data + capacity_size;
}
template <class T>
MyStack<T>::~MyStack()
{
    delete[] data;
}

template <class T>
bool MyStack<T>::Pop(T &out)
{
    bool ret;
    out = this->Pop(ret);
    return ret;
}

template <class T>
T MyStack<T>::Pop(bool &ret){
    if (this->IsEmpty())
    {
        ret = false;
        return T();
    }
    ret = true;
    head--;
    mSize--;
    return *head;
}

template <class T>
bool MyStack<T>::Push(const T &_pos)
{
    // std::cout << "aaa" << std::endl;
    if (this->IsFull())
    {
        T *tmp = data;
        capacity_size *= 2;

        std::cout << "再確保 size:" << capacity_size << "\n";
        data = new T[capacity_size];
        std::copy(tmp, head, data);

        head = data + mSize;
        capacity_last = data + capacity_size;

        // std::cout << "(" << data->x << ',' << data->y << ")\n";
        delete[] tmp;
    }

    *head = _pos;
    head++;
    mSize++;
    return true;
}

template <class T>
bool MyStack<T>::IsEmpty() const
{
    return mSize ? false : true;
}
template <class T>
bool MyStack<T>::IsFull() const
{
    return capacity_last == head;
}

template <class T>
void MyStack<T>::Show() const
{
    T *i = head - 1;
    std::cout << "\n";
    while (i >= data)
    {
        std::cout << "|" << *i << "|\n";
        i--;
    }
    std::cout << "-------------------------------\n";
}

template <class T>
int MyStack<T>::size() const
{
    return this->capacity_size;
}
template <class T>
int MyStack<T>::remain() const
{
    return this->capacity_size - this->mSize;
}

#endif
