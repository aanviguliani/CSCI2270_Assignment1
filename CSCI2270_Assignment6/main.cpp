#include <iostream>
#include "MovieTree.hpp"
#include <fstream>

using namespace std;

void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Print the inventory" << endl;
    cout << "2. Delete a movie" << endl;
    cout << "3. Quit" << endl;
}

int main(int argc, char const *argv[])
{
    ifstream fin(argv[1]);
    string line;
    MovieTree m1 = MovieTree();
    if(fin.is_open())
    {
        while (getline(fin, line))
        {
            stringstream sin(line);
            string ranking, title, year, rating;
            getline(sin, ranking, ',');
            getline(sin, title, ',');
            getline(sin, year, ',');
            getline(sin, rating);


            int _ranking = stoi(ranking);
            int _year = stoi(year);
            float _rating = stof(rating);

            m1.addMovie(_ranking,title,_year,_rating);
        }
    }
    fin.close();

    int choice = 0;
    string title;

    while(choice != 3)
    {
        displayMenu();
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
               m1.printMovieInventory();
               break;
            }
            case 2:
            {
                cout << "Enter title:" << endl;
                getline(cin,title);
                m1.deleteMovie(title);
                break;
            }

            case 3:
            {
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }

}