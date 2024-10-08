// OPTION 2 - IMPLEMENT STACK
// DO NOT SHARE

#include <cstdint>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

// 2. Implement a growable integer stack (without using container libraries like vector, list, etc.) 
//    that satisfies the following requirements:

// `push` adds a given value to the top
// `pop`  returns and removes the value at the top
// `peek` returns the value at the top
// `size` returns the count of values

/*
My Implementation: linked lists.
each value on the stack is a list node that contains its value and the pointer to the list node right beneath it on the stack
stack is initialized with size of 0 and a nullptr for its top node
everytime we add to the stack we allocate space for a new node, set its previous node as the current top node of the stack, and then stack the top node of the stack as the new node
everytime we pop we get the integer value stored in the top node, deallocate the top node, and return said integer
size is added everytime push is called and subtracted everytime pop is called: this might not be super well formed as an assumption, but since the stackNodes are private I doubt weird shenanigans can happen where nodes are changed/added without going through our push and pop functions.
error handling is done when top node is a nullptr, because this would only happen if the stack is empty
*/
struct StackNode {
    int value;
    StackNode* prevNode;
};
class IntStack {
private:
    int stacksize;
    StackNode* topNode;
public:
    IntStack() {
        stacksize = 0;
        topNode = nullptr;
        return;
    }
    void push(int input) {
        StackNode* n = new StackNode();
        n->value = input;
        n->prevNode = topNode;
        topNode = n;
        stacksize++;
    }
    int pop() {
        if (topNode == nullptr)
        {
            throw runtime_error("Attempting to pop an element off an empty stack.");
        }
        StackNode* currentTop = topNode;
        int output = currentTop->value;
        topNode = topNode->prevNode;
        stacksize--;
        delete currentTop;
        return output;
    }
    int peek() {
        if (topNode == nullptr)
        {
            throw runtime_error("Attempting to pop an element off an empty stack.");
        }
        return topNode->value;
    }
    int size() {
        return stacksize;
    }
};
int main()
{
    //the tests are performed in test.cpp
}
