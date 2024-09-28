//
// Created by saleha bilal on 28/09/2024.
//
#include "functions.h"

Node::Node() {
    data = 0;
    next = nullptr;
}

Node::~Node() {

}

int Node::getData() {
    return data;
}

void Node::setNext(Node *n) {
    this->next = n;
}

Node *Node::getNext() {
    return next;
}

void Node::setData(int d) {
    data = d;
}

//Stack

Stack::Stack() {
    count = 0;
    top = nullptr;
}

Stack::~Stack() {
    if(top){
        Node* next = nullptr;
        Node* current = top;
        for(int i = 0; i < count; i++){
            if(current!= nullptr) {
                next = current->getNext();
                delete current;
                current = next;
            }
        }
    }
}

bool Stack::isEmpty() {
    if(count == 0)
       return true;
    return false;
}

void Stack::push(int data) {
    Node *newData = new Node; // new Node
    newData->setData(data); // add data

    if(top)
        newData->setNext(top); // if top exists add top to the next of newData
    else
         newData->setNext(nullptr);  // if top does not exist newData points to null

    top = newData; // make newData top
    count++;
}

void Stack::pop() {
    if(top){
        Node* newTop = top->getNext(); // store next to top ptr
        delete top; // remove ptr
        top = newTop; // make next to node ptr
        count--;
    }
}

int Stack::peek() {
    if(top){
        return top->getData();
    }
    return -1;
}

int Stack::size() {
    return count;
}

void Stack::clear() {
    if(top){
        Node* next = nullptr;
        Node* current = top;
        for(int i = 0; i < count; i++){
            if(current) {
                next = current->getNext();
                delete current;
                current = next;
            }
        }
        count = 0;
    }
}

void Stack::printStack() {
    if(top) {
        Node *current = top;
        for (int i = 0; i < count; i++) {
            if(current) {
                cout << current->getData() << endl;
                current = current->getNext();
            }
        }
    }
}

// in queue insert at end and delete from start
Queue::Queue() {
    rear = nullptr;
    front = nullptr;
    count = 0;
}

Queue::~Queue() {
    if(front){
        Node* next = nullptr;
        Node* current = front;
        for(int i = 0; i < count; i++){
            if(current!= nullptr) {
                next = current->getNext();
                delete current;
                current = next;
            }
        }
    }
}

bool Queue::isEmpty() {
    if(count == 0)
        return true;
    return false;
}

//insert at end
void Queue::enqueue(int data) {
    Node* newData = new Node;
    newData->setData(data); // create new node and assign value
    if(front){
        rear->setNext(newData); // if front exists set newData to te next of rear
        rear = newData; // make rear nextData
    }
    else
        front = rear = newData; // if !front then front and rear is newData

    newData->setNext(nullptr); // next ptr of rear is always null
    count++;
}

// delete from start
void Queue::dequeue() {
    if(front){
        Node* next = front->getNext(); // get the next node to front
        delete front; // remove front
        front = next; // assign front the next of it
        count--;
    }
}

int Queue::size() {
    return count;
}

void Queue::printQueue() {
    if(front) {
        Node *current = front;
        for (int i = 0; i < count; i++) {
            if(current) {
                cout << current->getData() << endl;
                current = current->getNext();
            }
        }
    }
}

int Queue::peek() {
    if(front)
       return front->getData();
    return -1;
}
