#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include "Graph.hpp"

using namespace std;

int main(int argc, char const *argv[])
{
    int commas = 0; string line, noDist,city;
    Graph g1 = Graph();

    ifstream myfile(argv[1]);
    if(myfile.is_open())
    {
        getline(myfile,city);
        for(int i = 0; i < city.size(); i++)
        {
            if(city[i] == ',')
                commas++;
        }

        int j = 0; int a = 0; string word, list[commas];
        stringstream sin(city);
        getline(sin,word,',');
        while(getline(sin,word,','))
        {
            list[j++] = word;
            g1.addVertex(word);
        }
        int distances[commas];
        while(getline(myfile,line))
        {
            j = 0;
            stringstream sin2(line);
            getline(sin2,word,',');
            while(getline(sin2,word','))
            {
                distances[j] = stoi(word);
                if(distances[j] > 0)
                {
                    cout << " ... Reading in " << list[a] << " -- " << list[j] << " -- " << distances[j] << endl;
                    g1.addEdge(list[a],list[j],distances[j]);
                }
                j++;
            }
            a++;
        }
    }
    myfile.close();

    cout << "------------------------------ " << endl;
    cout << "Breadth First Traversal" << endl;
    cout << "------------------------------" << endl;
    g1.printBFT();
    cout << "------------------------------ " << endl;
    cout << "Depth First Traversal" << endl;
    cout << "------------------------------"<< endl;
    g1.printDFT();
    cout << "------------------------------ " << endl;
    cout << "Display Edges" << endl;
    cout << "------------------------------"<< endl;
    g1.displayEdges();

}