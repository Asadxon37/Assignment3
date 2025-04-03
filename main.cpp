#include <iostream>
#include "MyStack.h"

using namespace std;

int main() {
    MyStack<int> myStack;

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    cout<<"Top element: "<<myStack.top()<<endl;

    myStack.pop();

    cout<<"Top element after pop: "<<myStack.top()<<endl;

    myStack.pop();
    myStack.pop();

    try {
        myStack.pop();
    }catch (const std::logic_error &e){
        cout<<"Exception caught: "<<e.what();
    }
    return 0;
}