#ifndef MYSTACK_INCLUDEGARDE
#define MYSTACK_INCLUDEGARDE

struct POINT
{
    int x;
    int y;
    POINT() = default;
    POINT(int _x, int _y) : x(_x), y(_y) {}
};



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

    POINT Pop();
    void Push(POINT& _pos);

    bool IsEmpty();
    bool IsFull();
    void Show();
};

#endif