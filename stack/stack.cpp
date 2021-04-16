#include "stack.h"

#include <iostream>

Stack::Stack(int size) {
  arr = new int[size];
  capacity = size;
  top = -1;
}

Stack::~Stack() {
  delete[] arr;
}

void Stack::push(int number) {
  if(isFull()) {
    cout << "Stack overflow" << endl;
    exit(EXIT_FAILURE);
  }

  arr[++top] = number;
}

int Stack::pop() {
  if(isEmpty()) {
    cout << "Stack underflow" << endl;
    exit(EXIT_FAILURE);
  }

  return arr[top--];
}

int Stack::peek() {
  if (!isEmpty()) {
      return arr[top];
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