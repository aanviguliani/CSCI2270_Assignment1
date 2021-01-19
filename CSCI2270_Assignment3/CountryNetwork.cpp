/****************************************************************/
/*                CountryNetwork Implementation                 */
/****************************************************************/
/* TODO: Implement the member functions of class CountryNetwork */
/*     This class uses a linked-list of Country structs to      */
/*     represet communication paths between nations             */
/****************************************************************/

#include "CountryNetwork.hpp"
using namespace std;

/*
 * Purpose: Constructer for empty linked list
 * @param none
 * @return none
 */
CountryNetwork::CountryNetwork()
{
    head = NULL;
    //tail = NULL;
}


/*
 * Purpose: Check if list is empty
 * @return true if empty; else false
 */
bool CountryNetwork::isEmpty()
{
    if(head== NULL)
    {
        return true;
    }
    return false;
}


/*
 * Purpose: Add a new Country to the network
 *   between the Country *previous and the Country that follows it in the network.
 * @param previous name of the Country that comes before the new Country
 * @param countryName name of the new Country
 * @return none
 */
void CountryNetwork::insertCountry(Country* previous, string countryName)
{
    Country *current = new Country;
    current->name = countryName;

    if(previous==NULL)
    {
        current->next = head;
        head = current;
        cout << "adding: " << countryName << " (HEAD)" << endl;
        return;
    }
    current->next = previous->next;
    previous->next = current;
    cout << "adding: " << countryName << " (prev: " << previous->name << ")" << endl;
}


/*
 * Purpose: delete the country in the network with the specified name.
 * @param countryName name of the country to delete in the network
 * @return none
 */
void CountryNetwork::deleteCountry(string countryName)
{
    Country* temp = head;
    Country *previous;

    //if node to delete is at the head, free head
    if(temp != NULL && temp->name == countryName)
    {
        head = temp->next;
        free(temp);
        return;
    }

    //search through linked list and delete
    while(temp!=NULL && temp->name != countryName)
    {
        previous = temp;
        temp = temp->next;
    }

    if(temp==NULL)
    {
        cout << "Country does not exist." << endl;
        return;
    }

    previous->next = temp->next;
    free(temp);

}


/*
 * Purpose: populates the network with the predetermined countries
 * @param none
 * @return none
 */
void CountryNetwork::loadDefaultSetup()
{
    CountryNetwork::deleteEntireNetwork();
    CountryNetwork::insertCountry(NULL,"United States");
    CountryNetwork::insertCountry(CountryNetwork::searchNetwork("United States"),"Canada");
    CountryNetwork::insertCountry(CountryNetwork::searchNetwork("Canada"),"Brazil");
    CountryNetwork::insertCountry(CountryNetwork::searchNetwork("Brazil"),"India");
    CountryNetwork::insertCountry(CountryNetwork::searchNetwork("India"),"China");
    CountryNetwork::insertCountry(CountryNetwork::searchNetwork("China"),"Australia");
}


/*
 * Purpose: Search the network for the specified country and return a pointer to that node
 * @param countryName name of the country to look for in network
 * @return pointer to node of countryName, or NULL if not found
 * @see insertCountry, deletecountry
 */
Country* CountryNetwork::searchNetwork(string countryName)
{
    Country* current = head;
    while(current != NULL)
    {
        //cout << current->name << endl;
        if(current->name==countryName)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}


/*
 * Purpose: deletes all countries in the network starting at the head country.
 * @param none
 * @return none
 */
void CountryNetwork::deleteEntireNetwork()
{
    Country* current = head;
    if(head==NULL)
    {
        return;
    }
    while(head!=NULL)
    {
        current = head;
        cout << "deleting: " << head->name << endl;
        head = head->next;
        free(current);

    }
    cout << "Deleted network" << endl;
}


/*
 * Purpose: Transmit a message across the network to the
 *   receiver. Msg should be stored in each country it arrives
 *   at, and should increment that country's count.
 * @param receiver name of the country to receive the message
 * @param message the message to send to the receiver
 * @return none
 */
void CountryNetwork::transmitMsg(string receiver, string message)
{
    cout << endl;
    if(CountryNetwork::isEmpty())
    {
        cout << "Empty list" << endl;
        return;
    }

    Country *current = head;

    while(current != NULL)
    {
        current->message = message;
        current->numberMessages++;
        cout << current->name << " [# messages received: " << current->numberMessages << "] received: " << current->message << endl;
        if(current->name== receiver)
            break;
        current = current->next;
    }
    cout << endl;

}


/*
 * Purpose: prints the current list nicely
 * @param ptr head of list
 */
void CountryNetwork::printPath()
{
    Country *temp = head;

    if(CountryNetwork::isEmpty())
    {
        cout << "== CURRENT PATH ==" << endl;
        cout << "nothing in path" << endl;
        cout << "===" << endl;
        //cout << endl;
    }

    else{
        cout << "== CURRENT PATH ==" << endl;

        while(temp!=NULL)
        {
            cout <<temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

        cout << "===" << endl;
    }
    cout << endl;
}

/*
 * Purpose: reverse the entire network t
 * @param ptr head of list
 */
void CountryNetwork::reverseEntireNetwork()
{
    Country* current = head;
    Country* previous = NULL;
    Country* next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}