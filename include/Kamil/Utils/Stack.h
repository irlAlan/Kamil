#ifndef KAMIL_STACK_H
#define KAMIL_STACK_H

#include <iostream>
#include <string>

/**
 * @brief A stack in the Command namespace
 */
namespace Command{

// Dynamic stack array
template<typename T>
class Stack{
public:
    Stack(int);
    int getMax()const;
    void printStack()const;
    int pop();
    int push(T);
    void extend(int);
private:
    int max_size{};
    T* stack_array{new T[max_size]};
    T* SP = &stack_array[max_size];
    int SP_pos = max_size;
};

#endif

} // Command
