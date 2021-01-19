#include <string>
#include <iostream>
#include <map>
#include <fstream>
#include <sstream>
#include <queue>
#include "Graph.hpp"

using namespace std;

Graph::Graph()
{
}

Graph::~Graph()
{
}

void Graph::addVertex(std::string cityName)
{
    vertex* newCity = new vertex;
    newCity->name = cityName;
    vertices.push_back(*newCity);
}


void Graph::addEdge(std::string city1, std::string city2, int distance)
{
   Edge* newEdge = new Edge;
   newEdge->v = findVertex(city2);
   newEdge->distance = distance;
   findVertex(city1)->Edges.push_back(*newEdge);
}

void Graph::displayEdges()
{
    for (int i = 0; i < vertices.size(); i++)
    {
        cout << vertices[i].name << ":" << vertices[i].name << "-->";
        for (int j = 0; j < vertices[i].Edges.size(); j++)
        {
            cout << vertices[i].Edges[j].v->name << " ("
                 << vertices[i].Edges[j].distance << " miles)";
            if (j < vertices[i].Edges.size()-1)
            {
                cout << "***";
            }
        }
        cout << endl;
    }
}

void Graph::printDFT()
{
    setAllVerticesUnvisited();
    for(int i = 0; i < vertices.size(); i++)
    {
        if(vertices[i].visited == false)
        {
            DFT_traversal(&vertices[i]);
        }
    }
}

void Graph::DFT_traversal(vertex *v)
{
    v->visited = true;
    cout << v->name << endl;
    for(int i = 0; i < v->Edges.size(); i++)
    {
        if(!(v->Edges[i].v->visited))
        {
            DFT_traversal(v->Edges[i].v);
        }
    }
}

void Graph::printBFT()
{
    setAllVerticesUnvisited();
    for(int i=0; i<vertices.size(); i++) {
        if(vertices[i].visited==false) {
            BFT_traversal(&vertices[i]);
        }
    }
}

void Graph::BFT_traversal(vertex *v)
{
    queue <vertex*> q;
    q.push(v);
    v->visited = true;
    vertex* current;
    while(!q.empty())
    {
        current = q.front();
        q.pop();
        cout << current->name << endl;

        for (int i = 0; i < current->Edges.size(); i++)
        {
            if (!current->Edges[i].v->visited)
            {
                q.push(current->Edges[i].v);
                current->Edges[i].v->visited = true;
            }
        }
    }


}

void Graph::setAllVerticesUnvisited()
{
    for (int i = 0; i < vertices.size(); i++){
        vertices[i].visited = false;
    }
}

vertex* Graph::findVertex(string name)
{
    for (int i = 0; i < vertices.size(); i++)
    {
        vertex* v = &vertices[i];
        if(v->name == name)
        {
            return v;
        }
    }
    return NULL;
}

void Graph::findShortestPath(string start, string end)
{
    setAllVerticesUnvisited();

    vertex* startVertex = findVertex(start);
    vertex* endVertex = findVertex(end);



}

