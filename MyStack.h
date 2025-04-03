#ifndef MYSTACK_H
#define MYSTACK_H

#include <iostream>
#include <ranges>
#include <stdexcept>

template <typename T>
class MyStack {
private:
    class MyListNode {
    private:
        T value;
        MyListNode *next;

        public:
        MyListNode(T value):value(value),next(nullptr){}
        T getValue()const {return value;}
        void setNext(MyListNode* nextNode) { next = nextNode; }
        MyListNode *getNext()const {return next;}

    };
    MyListNode *head;
    public:
    MyStack():head(nullptr){}
    ~MyStack() {
        while (!empty()) {
            pop();
        }
    }
    bool empty() const { return head == nullptr; }
    T top()const {
        if (empty()) {
            throw std::logic_error("Stack is empty\n");
        }
        return head->getValue();
    }
    void pop() {
        if (empty()) {
            throw std::logic_error("Stack is empty\n");
        }
        MyListNode *p = head;
        p = p->getNext();
        delete p;
    }
    void push(T value) {
        MyListNode *newNode = new MyListNode(value);
        newNode->setNext(head);
        head = newNode;
    }
};


#endif //MYSTACK_H
