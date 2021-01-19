#include <iostream>
#include "MovieTree.hpp"

using namespace std;

MovieTree::MovieTree()
{
    root = NULL;
}

MovieTree::~MovieTree()
{
}

void print(MovieNode* root)
{
    MovieNode* temp = root;
    if(temp == NULL)
        return;
    print(temp->leftChild);
    cout << "Movie: " << temp->title << " " << temp->rating << endl;
    print(temp->rightChild);
}

void MovieTree::printMovieInventory()
{
    print(root);
}

void MovieTree::findMovie(string title)
{
    bool found = false;
    MovieNode* temp = root;
    while(temp!=NULL)
    {
        if(temp->title > title)
            temp = temp->leftChild;
        else if(temp->title < title)
            temp = temp->rightChild;
        else
        {
            cout << "Movie Info:" << endl;
            cout << "==================" << endl;
            cout << "Ranking:" << temp->ranking << endl;
            cout << "Title :" << temp->title << endl;
            cout << "Year :" << temp->year << endl;
            cout << "rating :" << temp->rating << endl;
            return;
        }
    }
    if(!found)
        cout << "Movie not found." << endl;
}

void MovieTree::addMovieNode(int ranking, std::string title, int year, float rating)
{
    //initialize vars
    MovieNode* temp = root;
    MovieNode* toAdd = new MovieNode;
    MovieNode* parent = new MovieNode;
    toAdd->ranking = ranking;
    toAdd->title = title;
    toAdd->year = year;
    toAdd->rating = rating;
    toAdd->rightChild = NULL;
    toAdd->leftChild = NULL;
    toAdd->parent = NULL;

    if(temp == NULL)
        root = toAdd;
    while(temp!=NU
    {
        parent = temp;
        if(toAdd->title < temp->title)
            temp = temp->leftChild;
        else
            temp = temp->rightChild;
    }
    if(parent == NULL)
        root = toAdd;
    else if(toAdd->title < parent->title)
    {
        parent->leftChild = toAdd;
        toAdd->parent = parent;
    }
    else
    {
        parent->rightChild = toAdd;
        toAdd->parent = parent;
    }
}

void findMovies(float rating, int year, MovieNode* root)
{
    MovieNode* temp = root;
    if(temp != NULL)
    {
        if(temp->rating > rating && temp->year > year)
            cout << temp->title << "(" << temp->year << ") " << temp->rating << endl;
        findMovies(rating,year,temp->leftChild);
        findMovies(rating,year,temp->rightChild);
    }
}

void MovieTree::queryMovies(float rating, int year)
{
    cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
    findMovies(rating,year,root);
}

float findSum(MovieNode* root)
{
    if(root == NULL)
        return 0;
    return (root->rating + findSum(root->leftChild) + findSum(root->rightChild));
}

int countNodes(MovieNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return countNodes(root->leftChild) + countNodes(root->rightChild) + 1;
    }
}

void MovieTree::averageRating()
{
    float sum = findSum(root);
    float count = float(countNodes(root));
    float averageRating = sum/count;
    if(count == 0)
        averageRating = 0;
    cout << "Average rating:" << averageRating << endl;
}
