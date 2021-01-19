/****************************************************************/
/*                Producer Consumer Driver File                 */
/****************************************************************/
/* TODO: Implement menu options as described in the writeup     */
/****************************************************************/

#include "ProducerConsumer.hpp"
#include <iostream>
// you may include more libraries as needed

using namespace std;

/*
 * Purpose: displays a menu with options
 * @param none
 * @return none
 */
void menu()
{
	cout << "*----------------------------------------*" << endl;
	cout << "Choose an option:" << endl;
    cout << "1. Producer (Produces items into the queue)" << endl;
	cout << "2. Consumer (Consumes items from the queue)" << endl;
	cout << "3. Return the queue size and exit" << endl;
	cout << "*----------------------------------------*" << endl;
}

int main(int argc, char const *argv[])
{
	ProducerConsumer obj;
	int choice = 0;
	int num = 0;
	string item;

	while(choice!=3)
	{
		menu();
		cin >> choice;

		switch(choice)
		{
			case 1:
				cout << "Enter the number of items to be produced:" << endl;
				cin >>  num;
				getline(cin,item);

				for(int i = 0; i < num; i++)
				{
					cout << "Item" << i+1 << ":" << endl;
					getline(cin,item);
					obj.enqueue(item);
				}
				break;
			case 2:
				cout << "Enter the number of items to be consumed:" << endl;
				cin >> num;

				for(int j = 0; j < num; j++)
				{
					if(!obj.isEmpty())
					{
						cout << "Consumed: " << obj.peek() << endl;
						obj.dequeue();
					}
					else
					{
						cout << "No more items to consume from queue" <<  endl;
						break;
					}
				}
				break;
			case 3:
				cout << "Number of items in the queue:" << obj.queueSize() << endl;
				break;
			default: cout << "Invalid option" << endl; break;
		}
	}
}
