#include <iostream>
#include <sstream>
#include <fstream>
#include "PriorityQueue.hpp"

using namespace std;

void displayMenu()
{
    cout << "============Main Menu============" << endl;
    cout << "1. Get group information from file" << endl;
    cout << "2. Add a group to Priority Queue" << endl;
    cout << "3. Show next group in the queue" << endl;
    cout << "4. Serve Next group" << endl;
    cout << "5. Serve Entire Queue" << endl;
    cout << "6. Quit" << endl;
}

int main(int argc, char const *argv[])
{

    PriorityQueue obj(stoi(argv[1]));
    int choice = 0;
    string filename;
    string line;
    string gname;
    int group = 0;
    int time = 0;
    int totalCookTime = 0;

    while(choice!=6)
    {
        displayMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
            {
                cout << "Enter filename:" << endl;
                getline(cin,filename);
                ifstream myfile(filename);
                if(myfile.is_open())
                {
                    while (getline(myfile, line))
                    {
                        stringstream sin(line);
                        string name,size,time;
                        getline(sin, name, ',');
                        getline(sin, size, ',');
                        getline(sin, time);

                        int _size = stoi(size);
                        int _time = stoi(time);

                        obj.enqueue(name,_size,_time);
                    }

                }
                break;
            }
            case 2:
            {
                cout << "Enter Group Name:" << endl;
                getline(cin,gname);
                getline(cin,gname);
                cout << "Enter Group Size:" << endl;
                cin >> group;
                cout << "Enter Estimated Cooking Time:" << endl;
                cin >> time;
                obj.enqueue(gname,group,time);
                break;
            }
            case 3:
            {
                if(obj.isEmpty())
                {
                    cout << "Heap empty, nothing to peek" << endl;
                }
                cout << "Group Name:" << obj.peek().groupName << endl;
                cout << "Group Size:" << obj.peek().groupSize << endl;
                cout << "Estimated Cooking Time:"<< obj.peek().cookingTime << endl;
                break;
            }
            case 4:
            {
                if(!obj.isEmpty())
                {
                    totalCookTime += obj.peek().cookingTime;
                    cout << "Group Name: " << obj.peek().groupName << " - Total Cook Time for the Group: " << totalCookTime << endl;
                    obj.dequeue();
                }
                else
                {
                    cout << "Heap empty, cannot dequeue" << endl;
                }
                break;
            }
            case 5:
            {
                if(obj.isEmpty())
                {
                    cout << "Heap empty, cannot dequeue" << endl;
                }
                while(!obj.isEmpty())
                {
                    totalCookTime += obj.peek().cookingTime;
                    cout << "Group Name: " << obj.peek().groupName << " - Total Cook Time for the Group: " << totalCookTime << endl;
                    obj.dequeue();
                }
            }
            case 6:
            {
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }
}