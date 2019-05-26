#include "CommunicationNetwork.h"
#include <fstream>
using namespace std;

CommunicationNetwork::CommunicationNetwork()
{
    head = NULL;
    tail = NULL;
}

void CommunicationNetwork::addCity(std::string nCity, std::string pCity)
{
    //If user wants to replace LA
    if(pCity == "First"){
        City *addHead = new City; //Sets new node pointed at what head is
        addHead->next= head;
        addHead->previous = NULL;
        addHead->cityName = nCity;
        addHead->message = "";
        head = addHead; //reinstate head
    }
    else{
        //Insert new city
        City *current = head;
        while(current->cityName != pCity and current->next != NULL){ // Finds previous city
            current = current->next;
        }
        City *returnNode = new City(nCity,current->next, current, ""); //same as above
        current->next = returnNode;
    }
}

void CommunicationNetwork::buildNetwork()
{
    //Builds network list
    std::string cityList[10] = {"Los Angeles", "Phoenix", "Denver", "Dallas", "St. Louis", "Chicago",
                                "Atlanta", "Washington, D.C.", "New York", "Boston"};
    //Instating head as LA
    head = new City;
    head->cityName = cityList[0];
    head->next = NULL;
    head->previous= NULL;
    head->message = "";
    City *current = head;

    //sets values of list
    int i = 1;
    while(i < 10){
        City *tmp = new City;
        tmp->cityName = cityList[i];
        tmp->message = "";
        tmp->next = NULL;
        tmp->previous = current;
        current->next = tmp;
        current = current->next;
        i++;
    }
    City *tail = current;
    current = head;
    cout<<"===CURRENT PATH==="<<endl;
    cout<<"NULL <- ";
    while(current != NULL){
        if(current->next == NULL){
            cout<<current->cityName<<" -> ";
            current = current->next;
        }
        else{
            cout<<current->cityName<<" <-> ";
            current = current->next;
        }
    }
    cout<<"NULL"<<endl;
    cout<<"=================="<<endl;
}

void CommunicationNetwork::transmitMsg(char *file) //this is like a string
{
    //Read in message
    ifstream inFile;
    inFile.open (file);
    string word;
    //Checks if list
    if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    //Reads message word by word and prints the word received
    while(inFile >> word){
        City *current = head;
        while(current != NULL){
            current->message = word;
            cout<<current->cityName<<" received "<<current->message<<endl;
            current->message = "";
            if(current->next == NULL){//Loop to display message back to head
                while(current->previous != NULL){
                    current = current->previous;
                    current->message = word;
                    cout<<current->cityName<<" received "<<current->message<<endl;
                    current->message = "";
                }
                break;
            }
            else {current = current->next;}
        }
    }
}

void CommunicationNetwork::printNetwork()
{
        City *current = head;
        cout<<"===CURRENT PATH==="<<endl;
        if(head !=NULL)
            cout<<"NULL <- ";
        while(current != NULL){
            if(current->next == NULL){
                cout<<current->cityName<<" -> ";
                current = current->next;
            }

            else{
                cout<<current->cityName<<" <-> ";
                current = current->next;
            }
        }
        cout<<"NULL"<<endl;
        cout<<"=================="<<endl;
}

void CommunicationNetwork::deleteCity(std::string name){
        City *current = head;
        City *tmp = new City;
        if(current->cityName == name){
            head = current->next;
            delete current;
            return;
        }
        while(current->cityName != name /*and current->next != NULL*/){ // Finds previous city
            if(current->next == NULL){
                cout<<"not found"<<endl;
                return;
            }
            current = current->next;
        }
        if(current->next == NULL){
            current->previous->next = NULL;
            delete current;
        } else{
        tmp = current->previous;
        current->next->previous = tmp;
        tmp->next = current->next;
        delete current;
        }



        // while(deleleCity->cityName != removeCity) //loop for cityname
    // {
    //  if(deleleCity->next==NULL)      //if cityname next equal null
    //  {
    //      cout<<"not found"<<endl;
    //      return;
    //  }
    //  deleleCity = deleleCity->next; 
    // }
    // if(deleleCity->next==NULL)
    // {
    //  deleleCity->prev->next=NULL;
    //  delete deleleCity;
    // }
    // else
    // {
    //  temp = deleleCity->prev;
    //  deleleCity->next->prev = temp;
    //  temp->next = deleleCity->next;
    //  delete deleleCity;
    // }
}


void CommunicationNetwork::deleteNetwork(){
    City *current = head;
    City *tmp = new City;
    if(current != NULL){
        while(current != NULL){ // Runs until all are deleted
            tmp = current->next;
            cout<<"deleting "<<current->cityName<<endl;
            delete current;
            current = tmp;
        }
        head = NULL;
    }
    delete current;
}

CommunicationNetwork::~CommunicationNetwork(){
    /*City *current = head;
    City *tmp = new City;
    if(current != NULL){
        while(current != NULL){ // Runs until all are deleted
            tmp = current->next;
            cout<<"deleting "<<current->cityName<<endl;
            delete current;
            current = tmp;
        }
        head = NULL;
    }
    delete current;*/
    deleteNetwork();
}