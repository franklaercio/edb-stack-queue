#ifndef STACK_H
#define STACK_H

using namespace std;

class Stack {
  private:
    int *arr;
    int top;
    int capacity;
  public:
    Stack(int size);
    ~Stack();

    void push(int number);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();  
};

#endif