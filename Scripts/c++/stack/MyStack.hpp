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


class MyStack
{
    POINT *data;
    POINT *head;

    POINT *capacity_last;

    int capacity_size;

public:
    int size;
    MyStack();
    ~MyStack();

    bool Pop(POINT& out);
    bool Push(const POINT& _pos);

    bool IsEmpty() const;
    bool IsFull() const;
    void Show() const;
};

#endif
