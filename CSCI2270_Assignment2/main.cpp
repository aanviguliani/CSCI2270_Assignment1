#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

struct wordItem
{
    string word;
    int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[])
{
    string line;
    ifstream myfile(ignoreWordFileName);
    {
        if(myfile.is_open())
        {
            int i = 0;
            while(getline(myfile,line))
            {
                ignoreWords[i++] = line;
            }
        }
    }
}

bool isStopWord(string word, string ignoreWords[])
{
    for(int i = 0; i < 50; i++)
    {
        if(word == ignoreWords[i])
        {
            return true;
        }
    }

    return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[],int length)
{
    int total = 0;
    for(int i = 0; i < length; i++)
    {
        total = total + uniqueWords[i].count;
    }
    return total;
}

void printTopN(wordItem uniqueWords[], int topN, int totalNumWords)
{
    //cout << "Probabilities of top "<< topN << " most frequent words" << endl;
    for(int i = 0; i < topN; i++)
    {
        float probability = float(uniqueWords[i].count)/(totalNumWords);
        cout << std::fixed << std::setprecision(4)<< probability;
        cout << " - " << uniqueWords[i].word << endl;
    }
}

void arraySort(wordItem uniqueWords[], int length)
{
    wordItem temp;
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length-i-1; j++){
            if(uniqueWords[j].count < uniqueWords[j+1].count){
                temp = uniqueWords[j];
                uniqueWords[j] = uniqueWords[j+1];
                uniqueWords[j+1] = temp;

            }
        }

    }
}

int main(int argc, char const *argv[])
{
    if(argc != 4)
    {
        cerr << "Usage: CSCI2270_Assignment2 <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    }

    else
    {
        string fileName = argv[2];
        int arraySize = 100;
        wordItem* words = new wordItem[arraySize];
        string ignoreWords[50];
        int numTimesDoubled = 0;

        getStopWords(argv[3],ignoreWords);
        ifstream myfilestream(fileName);
        int i = 0;

        if(myfilestream.is_open())
        {
            //cout << "open" << endl;
            string line;

            while(!myfilestream.eof())
            {
                int numEntries = 1;
                words[i].count = 1;
                myfilestream >> line;
                if(!isStopWord(line,ignoreWords))
                {
                    for(int j = 0; j <= i; j++)
                    {
                        if(line == words[j].word)
                        {
                            words[j].count++;
                            numEntries = 0;
                        }

                    }

                    if(numEntries == 1)
                    {
                        words[i++].word = line;
                    }
                    if(i==arraySize)
                    {
                        arraySize = 2*arraySize;
                        wordItem* wordsNew = new wordItem[arraySize];

                        for(int c=0; c < arraySize/2; c++) {
                            wordsNew[c] = words[c];
                        }

                        delete[] words;
                        words = wordsNew;
                        numTimesDoubled++;
                    }
                }
            }

            arraySort(words,i);

            int totalNumWords = getTotalNumberNonStopWords(words,i);

            cout << "Array doubled: " << numTimesDoubled << endl;
            cout << "#" << endl;
            cout << "Unique non-common words: " << i << endl;
            cout << "#" << endl;
            cout << "Total non-common words: " << totalNumWords << endl;
            cout << "#" << endl;
            cout << "Probabilities of top " << stoi(argv[1]) << " most frequent words" << endl;
            cout << "---------------------------------------" << endl;
            printTopN(words,stoi(argv[1]),totalNumWords);

        }

        else
        {
            cerr << "Failed to open " << argv[2] << endl;
        }
    }
}