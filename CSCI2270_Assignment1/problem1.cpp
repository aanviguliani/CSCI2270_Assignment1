#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int insertIntoSortedArray(int myArray[], int numEntries, int newValue)
{
    myArray[numEntries] = newValue;
    numEntries++;
    int temp = 0;
    //cout<<newValue<<endl;
    for(int i=0; i<numEntries; i++)
    {
        for(int c=0;c<numEntries-i-1;c++)
        {
            if(myArray[c]>myArray[c+1])
            {
                temp = myArray[c];
                myArray[c] = myArray[c+1];
                myArray[c+1] = temp;
            }
        }
    }

    for(int i=0; i<numEntries; i++)
    {
        if(i != numEntries -1)
            cout << myArray[i] << ",";
        else
            cout << myArray[i];
    }
    cout << endl;

    return numEntries;
}

int main(int argc, char const *argv[])
{
    if(argc != 2)
    {
        cerr << "Error: incorrect number of arguments \n";
    }

    else
    {
        ifstream myfilestream(argv[1]);
        if(myfilestream.is_open())
        {
            int arr[100];
            string line;
            int numEntries = 0;

            while(getline(myfilestream,line))
            {
                //cout << line << endl;
                int newValue = stoi(line);
                numEntries = insertIntoSortedArray(arr,numEntries,newValue);
            }

        }

        else
        {
            cerr << "Failed to open the file. \n";
        }
    }
}