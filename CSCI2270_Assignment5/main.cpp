#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "MovieTree.hpp"

using namespace std;

void displayMenu()
{
    cout << "======Main Menu======" << endl;
    cout << "1. Find a movie" << endl;
    cout << "2. Query movies" << endl;
    cout << "3. Print the inventory" << endl;
    cout << "5. Quit" << endl;
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

            m1.addMovieNode(_ranking,title,_year,_rating);
        }
    }
    fin.close();

    int choice = 0;
    string title;
    float minRating = 0.0;
    int minYear = 0;

    while(choice!=5)
    {
        displayMenu();
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                cout << "Enter title:" << endl;
                getline(cin,title);
                m1.findMovie(title);
                break;
            }
            case 2:
            {
                cout << "Enter minimum rating:" << endl;
                cin >> minRating;
                cout << "Enter minimum year:" << endl;
                cin >> minYear;

                m1.queryMovies(minRating,minYear);
                break;
            }
            case 3:
            {
                m1.printMovieInventory();
                break;
            }
            case 4:
            {
                m1.averageRating();
                break;
            }
            case 5:
            {
                cout << "Goodbye!" << endl;
                break;
            }
        }
    }

}