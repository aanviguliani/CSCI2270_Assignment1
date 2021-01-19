#include <iostream>
#include "HashTable.hpp"
#include <fstream>
#include <string>
#include <stdio.h>
#include <iomanip>

using namespace std;

wordItem* createNode(string word, wordItem* next)
{
    wordItem* nw = new wordItem;
    nw->word = word;
    nw->next = next;
    return nw;
}

HashTable::HashTable(int hashTableSize)
{
    hashTable = new wordItem* [hashTableSize];
    for(int i = 0; i < hashTableSize; i++)
    {
        hashTable[i] = NULL;
    }
    numItems = 0;
    numCollisions = 0;
    this->hashTableSize = hashTableSize;
}

HashTable::~HashTable()
{
    delete[] hashTable;
}

unsigned int HashTable::getHash(string word)
{
    int hash = 5381;
    for(int i = 0; i < word.length(); i++)
    {
        hash = (hash * 33) + i;
    }
    hash = hash % hashTableSize;
    if(hash < 0)
        hash += hashTableSize;
    return hash;
}

wordItem* HashTable::searchTable(std::string word)
{
    //Compute the index by using the hash function
    int index = getHash(word);

    //TODO: Search the list at that specific index and return the node if found
    if(hashTable[index] != NULL)
    {
        wordItem* temp = hashTable[index];
        while(temp != NULL)
        {
            if(temp->word == word)
                return temp;
            else
                temp = temp->next;
        }

    }
    return NULL;
}

void HashTable::addWord(std::string word)
{
    if(!searchTable(word))
    {
        // TODO :
        int index = getHash(word);
        wordItem* temp = hashTable[index];
        numItems++;
        if(temp == NULL)
        {
            hashTable[index] = createNode(word,NULL);
            return;
        }
        else
        {
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = createNode(word,NULL);
            numCollisions++;
            return;
        }
    }
    else
    {
        wordItem* found = searchTable(word);
        numItems++;
        return;
    }
}

void getStopWords(char* ignoreWordFileName,HashTable &stopWordsTable)
{
    string word;
    ifstream myfile(ignoreWordFileName);
    if(myfile.is_open())
    {
        while(myfile >> word)
        {
            stopWordsTable.addWord(word);
        }
    }
}

int HashTable::getTotalNumWords()
{
    int count = 0;
    for(int i = 0; i < hashTableSize;i++)
    {
        if(hashTable[i] != NULL)
        {
            wordItem* temp = hashTable[i];
            while(temp != NULL)
            {
                count = count + temp->count;
                temp = temp->next;
            }
        }
    }
    return count;
}

void HashTable::printTopN(int n)
{
    int totalWords = getTotalNumWords();
    int max = 0;
    for(int i = 0; i < n; i++)
    {
        int tempCount = 0;
        string tempWord;

        for(int j = 0; j < hashTableSize; j++)
        {
            wordItem* temp = hashTable[j];
            while(temp != NULL)
            {
                if(i == 0)
                {
                    if(temp->count > tempCount)
                    {
                        tempCount = temp->count;
                        tempWord = temp->word;
                    }
                }
                else
                {
                    if(temp->count > tempCount && temp->count < max)
                    {
                        tempCount = temp->count;
                        tempWord = temp->word;
                    }
                }
                temp = temp->next;
            }

        }
        max = tempCount;
        cout << fixed << showpoint;
        cout << setprecision(4);
        cout << (float)tempCount / totalWords << " - " << tempWord << endl;
    }
}

int HashTable::getNumCollisions()
{
    return numCollisions;
}

int HashTable::getNumItems()
{
    return numItems;
}

bool HashTable::isInTable(std::string word)
{
    return (searchTable(word) != NULL);
}

void HashTable::incrementCount(std::string word)
{
    int index = getHash(word);
    wordItem* temp = hashTable[index];

    while(temp->word != word)
    {
        temp = temp->next;
    }
    temp->count++;
}

bool isStopWord(string word,HashTable &stopWordsTable)
{
    return (stopWordsTable.isInTable(word));
}