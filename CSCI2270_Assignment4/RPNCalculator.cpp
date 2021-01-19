#include "RPNCalculator.hpp"
#include <iostream>
using namespace std;

RPNCalculator::RPNCalculator()
{
    stackHead = nullptr;
}

RPNCalculator::~RPNCalculator()
{
    while(!isEmpty())
    {
        pop();
    }
}

bool RPNCalculator::isEmpty()
{
    if(stackHead==nullptr)
    {
        return true;
    }
    return false;
}

void RPNCalculator::push(float num)
{
    Operand* temp = new Operand;
    temp->number = num;
    temp->next = nullptr;
    temp->next = stackHead;
    stackHead = temp;
}

void RPNCalculator::pop()
{
    if(!isEmpty())
    {
        Operand* temp = stackHead;
        stackHead = stackHead->next;
        delete temp;
    }
    else
        cout << "Stack empty, cannot pop an item." << endl;

}

Operand* RPNCalculator::peek()
{
    if(!isEmpty())
    {
        return stackHead;
    }
    else
    {
        cout << "Stack empty, cannot peek." << endl;
        return NULL;
    }
}

bool RPNCalculator::compute(std::string symbol)
{
    Operand* temp = new Operand;
    Operand* temp2 = new Operand;
    float f1 = 0;
    float f2 = 0;
    float result = 0;

    if(symbol == "+" || symbol == "*")
    {
        if(isEmpty())
        {
            cout << "err: not enough operands" << endl;
            return false;
        }
        temp = peek();
        f1 = temp->number;
        pop();
        if(isEmpty())
        {
            push(f1);
            cout << "err: not enough operands" << endl;
            return false;
        }
        temp2 = peek();
        f2 = temp2->number;
        pop();
        if(symbol == "+")
        {
            result = f1 + f2;
        }
        else if(symbol == "*")
        {
            result = f1*f2;
        }
        push(result);
    }

    else
    {
        cout << "err: invalid operation" << endl;
        return false;
    }
    return true;
}