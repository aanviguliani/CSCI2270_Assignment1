#include "MovieTree.hpp"
#include <iostream>

using namespace std;

MovieTree::MovieTree()
{
    root = NULL;
}

void deleteLLHelper(LLMovieNode* temp)
{
    LLMovieNode* next;

    while(temp!= NULL)
    {
        next = temp->next;
        delete temp;
        temp = next;
    }
}

void deleteTree(TreeNode* temp)
{
    if(temp == NULL)
        return;

    deleteTree(temp->leftChild);
    deleteTree(temp->rightChild);
    delete temp;
}

void deleteLL(TreeNode* temp)
{
    if(temp == NULL)
        return;

    deleteLL(temp->leftChild);
    deleteLLHelper(temp->head);
    deleteLL(temp->rightChild);
}

MovieTree::~MovieTree()
{
    deleteLL(root);
    deleteTree(root);
}

void printMovieRecursive(TreeNode* root)
{
    if(root == NULL)
        return;
    if(root->leftChild != NULL)
    {
        printMovieRecursive(root->leftChild);
    }
    cout << "Movies starting with letter: " << root->titleChar << endl;
    LLMovieNode* temp = root->head;
    while(temp!= NULL)
    {
        cout << " >> " << temp->title << " " << temp->rating << endl;
        temp = temp->next;
    }
    if(root->rightChild !=NULL)
    {
        printMovieRecursive(root->rightChild);
    }
}


void MovieTree::printMovieInventory()
{
    printMovieRecursive(root);
}

TreeNode* searchRecursive(TreeNode* node, char key)
{
    if (node == NULL || node->titleChar == key)
        return node;
    if(node->titleChar < key)
        return searchRecursive(node->rightChild,key);
    if(node->titleChar > key)
        return searchRecursive(node->leftChild,key);
}

void addLLNode(TreeNode* node, int ranking, string title, int year, float rating)
{
    LLMovieNode* toAdd = new LLMovieNode;
    toAdd->ranking = ranking;
    toAdd->title = title;
    toAdd->rating = rating;
    toAdd->year = year;
    toAdd->next = NULL;

    LLMovieNode* current= node->head;
    LLMovieNode* previous;

    if(current == NULL)
    {
        node->head = toAdd;
        return;
    }
    else if(current->title > title)
    {
        toAdd->next = node->head;
        node->head = toAdd;
        return;
    }
    else
    {
        while(current->title < title)
        {
            if(current->next == NULL)
            {
                current->next = toAdd;
                return;
            }
            else
            {
                previous = current;
                current = current->next;
            }
        }
        toAdd->next = previous->next;
        previous->next = toAdd;
    }
}

TreeNode* addBSTNode(TreeNode* node, char title)
{
    TreeNode* toAdd = new TreeNode;
    toAdd->titleChar = title;
    toAdd->leftChild = NULL;
    toAdd->rightChild = NULL;
    toAdd->head = NULL;

    while(true)
    {
        if(node->titleChar > title)
        {
            if(node->leftChild == NULL)
            {
                toAdd->parent = node;
                node->leftChild = toAdd;
                break;
            }
            else
            {
                node = node->leftChild;
            }
        }
        else if(node->titleChar < title)
        {
            if(node->rightChild == NULL)
            {
                toAdd->parent = node;
                node->rightChild = toAdd;
                break;
            }
            else
            {
                node = node->rightChild;
            }
        }
    }
    return toAdd;

}

void MovieTree::addMovie(int ranking, string title, int year, float rating)
{
    char letter =  title[0];
    if(root == NULL)
    {
        TreeNode* newNode = new TreeNode;
        newNode->titleChar = letter;
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->parent = NULL;

        root = newNode;
        addLLNode(newNode,ranking,title,year,rating);
    }
    else
    {
        TreeNode* temp = searchRecursive(root,letter);
        if(temp != NULL)
        {
            addLLNode(temp,ranking,title,year,rating);
        }
        else
        {
            temp = addBSTNode(root,letter);
            addLLNode(temp,ranking,title,year,rating);
        }
    }
}
TreeNode* getMinLetterNode(TreeNode* currNode){

    if(currNode->leftChild == NULL){
        return currNode;
    }
    return getMinLetterNode(currNode->leftChild);
}

TreeNode* deleteBSTNode(TreeNode* currNode, char letter)
{
    if(currNode == NULL)
    {
        return NULL;
    }
    else if(letter < currNode->titleChar)
    {
        currNode->leftChild = deleteBSTNode(currNode->leftChild, letter);
    }
    else if(letter > currNode->titleChar)
    {
        currNode->rightChild = deleteBSTNode(currNode->rightChild, letter);
    }
    else
    {
        if(currNode->leftChild == NULL)
        {
            TreeNode* temp = currNode->rightChild;
            delete(currNode);
            return temp;
        }
        else if(currNode->rightChild == NULL)
        {
            TreeNode* temp = currNode->leftChild;
            delete(currNode);
            return temp;
        }
        else
        {
            TreeNode* temp = getMinLetterNode(currNode->rightChild);
            currNode->titleChar = temp->titleChar;
            currNode->head = temp->head;
            currNode->rightChild = deleteBSTNode(currNode->rightChild,temp->titleChar);
        }

    }
    return currNode;
}

bool deleteLLNode(TreeNode* temp, string title)
{
    LLMovieNode* current = temp->head;
    LLMovieNode* previous;

    if(current->title == title)
    {
        if(current->next == NULL)
        {
            delete current;
            temp->head = NULL;
            return true;
        }
        else
        {
            temp->head = current->next;
            delete current;
            return false;
        }

    }
    else
    {
        while(current->title != title)
        {
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        delete current;
        return false;
    }
}

void MovieTree::deleteMovie(string title)
{
    char letter = title[0];
    bool isEmpty;

    if(root == NULL)
    {
        cout << "Movie: " << title << " not found, cannot delete." << endl;
    }
    else
    {
        TreeNode* temp = searchRecursive(root,letter);
        isEmpty = deleteLLNode(temp,title);
        if(isEmpty)
        {
            root = deleteBSTNode(root,letter);
        }

    }
}
