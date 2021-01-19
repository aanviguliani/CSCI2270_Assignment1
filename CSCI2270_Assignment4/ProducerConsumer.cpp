#include "ProducerConsumer.hpp"
#include <iostream>
using namespace std;

ProducerConsumer::ProducerConsumer()
{
    queueFront = -1;
    queueEnd = -1;
}

bool ProducerConsumer::isEmpty()
{
    if(queueFront = -1)
        return true;
    return false;
}

bool ProducerConsumer::isFull()
{
    if((queueFront == 0 && queueEnd == SIZE-1) || queueFront == queueEnd +1)
    {
        return true;
    }
    return false;
}

void ProducerConsumer::enqueue(std::string player)
{
    if(!isFull())
    {
        if(queueFront == -1)
        {
            queueFront = 0;
            queueEnd++;
        }
        else if(queueEnd == SIZE - 1)
        {
            queueEnd = 0;

        }
        else
        {
            queueEnd++;
        }
        queue[queueEnd] = player;
    }
    else
    {
        cout << "Queue full, cannot add new item" << endl;
    }
}

void ProducerConsumer::dequeue()
{
    if(!isEmpty())
    {
        if(queueFront == queueEnd)
        {
            queueFront = -1;
            queueEnd = -1;
        }
        else if(queueFront == SIZE -1)
        {
            queueFront = 0;
        }
        else
        {
            queueFront++;
        }
    }
    else
        cout << "Queue empty, cannot dequeue an item" << endl;
}

int ProducerConsumer::queueSize()
{
    if(queueFront == -1)
    {
        return 0;
    }
    return (queueFront+queueEnd+1);
}

string ProducerConsumer::peek()
{
    string item;
    if(!isEmpty())
    {
        item = queue[queueFront];

    }
    else
    {
        cout << "Queue empty, cannot peek" << endl;
    }
    return item;
}