#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct User
{
    string username;
    float gpa;
    int age;
};

void addUser(User users[], string _username, float _gpa, int _age, int length)
{
    //cout << "in add user" << endl;
    users[length].username = _username;
    users[length].gpa = _gpa;
    users[length].age = _age;
}

void printList(const User users[], int length)
{
    for(int i = 0; i < length; i++)
    {
        cout << users[i].username << " ";
        cout << "[" << users[i].gpa << "]" << " ";
        cout << "age: " << users[i].age << endl;
    }
}

int main(int argc, char const *argv[])
{
    /*if(argc != 4)
    {
        cerr << "Error: incorrect number of arguments \n";
    }*/

    //else
    //{
    ifstream fin(argv[1]);
    User userStruct[100];
    int size = 0;
    string line;

    if(fin.is_open())
    {
        while (getline(fin, line))
        {
            stringstream sin(line);
            string username, gpa, age;
            getline(sin, username, ',');
            getline(sin, gpa, ',');
            getline(sin, age);
            //cout << "hello" << endl;
            /*cout << username << endl;
            cout << gpa << endl;
            cout << age << endl;*/

            float _gpa = stof(gpa);
            int _age = stoi(age);

            addUser(userStruct, username,_gpa,_age,size);
            size++;
        }
    }
    /*else
    {
        cout << "not opening" << endl;
    }*/

    printList(userStruct,size);

    fin.close();

    ofstream output(argv[2]);
    float minGPA = stof(argv[3]);
    for(int i = 0; i < size; i++)
    {
        if(userStruct[i].gpa >= minGPA)
        {
            output << userStruct[i].username <<"," << userStruct[i].gpa << "," << userStruct[i].age << endl;
        }
    }
    return 0;
    //}




}
