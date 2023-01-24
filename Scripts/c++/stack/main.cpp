#include <iostream>
#include <random>

#include "MyStack.hpp"

int main(){
    MyStack<POINT> stack;
    bool ret;
    bool loop = true;
    int res;
    POINT p;

    std::random_device seed_gen;
    std::mt19937 engine(seed_gen());

    std::uniform_int_distribution<> dist(-100,100);

    while(loop){
        std::cout << "0) 終了\n";
        std::cout << "1) PUSH\n";
        std::cout << "2) POP\n";

        std::cout << "\nどの操作をしますか？:";
        std::cin >> res;

        switch(res){
            case 0:
                goto loopEnd;
            case 1:
                ret = stack.Push(POINT(dist(engine),dist(engine)));
                if(!ret){
                    std::cout << "Stack is Error\n";
                }
                break;
            case 2:
                ret = stack.Pop(p);

                if(ret){
                    std::cout << "pop: >>" << p;
                }
                else{
                    std::cout << "Stack is Empty\n";
                }

                break;
            case 3:
                stack.Show();
                break;
            default:
                std::cout << "ちゃんと入力して\n";
        }
        stack.Show();
    }
loopEnd:

    std::cout << "exit\n";
    return 0;
}
