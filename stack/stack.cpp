#include "stack.h"

#include <iostream>

Stack::Stack(int size) {
  array = new int[size];
  capacity = size;
  top = -1;
}

Stack::~Stack() {
  delete[] array;
}

void Stack::push(int number) {
  if(isFull()) {
    cout << "Stack overflow" << endl;
    exit(EXIT_FAILURE);
  }

  array[++top] = number;
}

int Stack::pop() {
  if(isEmpty()) {
    cout << "Stack underflow" << endl;
    exit(EXIT_FAILURE);
  }

  return array[top--];
}

int Stack::peek() {
  if (!isEmpty()) {
      return array[top];
  } else {
      exit(EXIT_FAILURE);
  }
}

int Stack::size() {
  return top + 1;
}

bool Stack::isEmpty() {
  return top == -1;            
}

bool Stack::isFull() {
  return top == capacity - 1;
}