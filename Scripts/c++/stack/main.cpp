#include <iostream>

#include "MyStack.hpp"

int main(){
    POINT posA(1,1);
    POINT posB(2,2);
    POINT posC(3,3);
    MyStack A;
    A.Push(posA);
    A.Push(posB);
    A.Push(posC);

    A.Show();
    A.Pop();
    A.Pop();
    A.Pop();
}