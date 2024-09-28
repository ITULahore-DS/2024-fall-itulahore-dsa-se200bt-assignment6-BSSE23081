//
// Created by saleha bilal on 28/09/2024.
//

#ifndef INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23081_FUNCTIONS_H
#define INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23081_FUNCTIONS_H
using namespace std;
#include <iostream>
#include <stdexcept>

class Node{
    int data;
    Node* next;
public:
    Node();
    ~Node();
    void setNext(Node* next);
    Node* getNext();
    void setData(int data);
    int getData();
};

class Stack{
    Node* top;
    int count;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    void push(int data);
    void pop();
    int peek();
    int size();
    void clear();
    void printStack();
};

class Queue{
    Node* front;
    Node* rear;
    int count;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void enqueue(int data);
    void dequeue();
    int size();
    void printQueue();
};


#endif //INC_2024_FALL_ITULAHORE_DSA_SE200BT_ASSIGNMENT6_BSSE23081_FUNCTIONS_H
