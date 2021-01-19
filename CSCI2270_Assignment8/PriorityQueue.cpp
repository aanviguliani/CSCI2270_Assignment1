#include <iostream>
#include "PriorityQueue.hpp"

using namespace std;

PriorityQueue::PriorityQueue(int queueSize)
{
    maxQueueSize = queueSize;
    currentQueueSize = 0;
    priorityQueue = new GroupNode[queueSize];
}

PriorityQueue::~PriorityQueue()
{
    delete [] priorityQueue;
}


void PriorityQueue::enqueue(std::string _groupName, int _groupSize, int _cookingTime)
{
    if(isFull())
    {
        cout << "Heap full, cannot enqueue" << endl;
        return;
    }
    GroupNode* temp = new GroupNode;
    temp->cookingTime = _cookingTime;
    temp->groupSize = _groupSize;
    temp->groupName = _groupName;
    priorityQueue[currentQueueSize] = *temp;
    repairUpward(currentQueueSize);
    currentQueueSize++;
}

int parent(int index)
{
    return (index-1)/2;
}

void PriorityQueue::repairUpward(int nodeIndex)
{
    GroupNode temp;
    while (nodeIndex != 0 && (priorityQueue[parent(nodeIndex)].groupSize > priorityQueue[nodeIndex].groupSize || (priorityQueue[parent(nodeIndex)].groupSize == priorityQueue[nodeIndex].groupSize && priorityQueue[parent(nodeIndex)].cookingTime > priorityQueue[nodeIndex].cookingTime)))
    {
        temp = priorityQueue[nodeIndex];
        priorityQueue[nodeIndex] = priorityQueue[parent(nodeIndex)];
        priorityQueue[parent(nodeIndex)] = temp;
        nodeIndex = parent(nodeIndex);
    }
}

void PriorityQueue::dequeue()
{
    if(isEmpty())
    {
        cout << "Heap empty, cannot dequeue" << endl;
        return;
    }

    priorityQueue[0] = priorityQueue[currentQueueSize-1];
    currentQueueSize--;
    repairDownward(0);

}

int leftChild(int index)
{
    return ((2*index) + 1);
}

int rightChild(int index)
{
    return ((2*index) + 2);
}

void PriorityQueue::repairDownward(int nodeIndex)
{
    int l = leftChild(nodeIndex);
    int r = rightChild(nodeIndex);
    int smallest = nodeIndex;
    GroupNode temp;

    if(l < currentQueueSize && (priorityQueue[l].groupSize < priorityQueue[nodeIndex].groupSize || (priorityQueue[l].groupSize == priorityQueue[nodeIndex].groupSize && priorityQueue[l].cookingTime < priorityQueue[nodeIndex].cookingTime)))
    {
        smallest = l;
    }
    if(r < currentQueueSize && (priorityQueue[r].groupSize < priorityQueue[smallest].groupSize || (priorityQueue[r].groupSize == priorityQueue[smallest].groupSize && priorityQueue[r].cookingTime < priorityQueue[smallest].cookingTime)))
    {
        smallest = r;
    }
    if(smallest != nodeIndex)
    {
        temp = priorityQueue[nodeIndex];
        priorityQueue[nodeIndex] = priorityQueue[smallest];
        priorityQueue[smallest] = temp;
        repairDownward(smallest);
    }
}

GroupNode PriorityQueue::peek()
{
    if(isEmpty())
    {
        cout << "Heap empty, nothing to peek" << endl;
    }
    return priorityQueue[0];

}

bool PriorityQueue::isFull()
{
    if(currentQueueSize == maxQueueSize)
        return true;
    return false;
}

bool PriorityQueue::isEmpty()
{
    if(currentQueueSize == 0)
        return true;
    return false;
}