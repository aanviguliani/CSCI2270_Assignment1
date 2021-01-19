#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "HashTable.hpp"

using namespace std;

int main(int argc, char* const argv[])
{
    HashTable stopWords(STOPWORD_TABLE_SIZE);
    int tableSize = atoi(argv[4]);
    int topN = atoi(argv[1]);
    HashTable table(tableSize);

    getStopWords(argv[3],stopWords);
    string word;
    ifstream myfile(argv[2]);

    if(myfile.is_open())
    {
        while(myfile>>word)
        {
            if(!stopWords.isInTable(word))
            {
                table.addWord(word);
            }
            else
            {
                table.incrementCount(word);
            }
        }
    }
    myfile.close();
    table.printTopN(topN);
    cout << "#" << endl;
    cout << "Number of collisions: " << table.getNumCollisions() << endl;
    cout << "#" << endl;
    cout << "Unique non-stop words: " << table.getNumItems() << endl;
    cout << "#" << endl;
    cout << "Total non-stop words: " << table.getTotalNumWords() << endl;
}