//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 6/29/2018
//Assignment3


#include "CommunicationNetwork.h"

#include<iostream>
#include<fstream>
#include<string>

using namespace std;
//help function to create linked list
City* create_city(string cityName, City* nextNode)
{
	City* newCity = new City; //create new city
	newCity->cityName = cityName; 
	newCity->next = nextNode;
	return newCity;
}
//help function to add city into linked list
City* insert_new_city(City* head, string city_name)
{
	if(head==NULL)
	{
		City* newNode = create_city(city_name, NULL);
		head = newNode;
		//head->next->prev = head;
	}
	else
	{
		City* newNode = create_city(city_name, head);
		head = newNode;

	}
	return head;
}

//constructor
CommunicationNetwork::CommunicationNetwork()
{
	head = NULL;
	tail = NULL;
}

//deconstructor
//delete the linked list
CommunicationNetwork::~CommunicationNetwork()
{
	deleteNetwork();
}

/*
* Write function name: addCity;
*Purpose: to add new city to linked list in front/middle/tail of linked list
*@param newCityName - new city that want to add to linked list
*@param previousCityName - city before add new city
* @return - none
*/
void CommunicationNetwork::addCity(string newCityName, string previousCityName)
{
	
	
	if (previousCityName == "First") {
		
		City* newhead = new City;
		newhead->cityName = newCityName;
		newhead->next = head;
		head = newhead;

	}
	else if (previousCityName == "") {

		//cout<<"test1"<<endl;
		City* newtail = new City;
		newtail->cityName = newCityName;
		newtail->next = NULL;
		City* temp = head;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
			temp->next = newtail;
	}
	else {
		City* temp = head;
		while (temp!=NULL && temp->cityName != previousCityName)
		{
			temp = temp->next;
		}

		if (temp == NULL) {
			cout << previousCityName<<" not found" << endl;
		}
		else {
			City* newCity = new City;
			newCity->cityName = newCityName;
			newCity->next = temp->next; //new city pointer point to next city
			temp->next = newCity; //temp pointer point to newCity node
		}
	}
	
}

/*
* Write function name: buildNetwork;
*Purpose: add city into linked list
*@param NONE
* @return - none
*/
void CommunicationNetwork::buildNetwork()
{
	head = insert_new_city(head, "Boston"); //call insert_new_city function to add city to head 
	head = insert_new_city(head, "New York");
	head = insert_new_city(head, "WashingTon, D.C.");
	head = insert_new_city(head, "Atlanta");
	head = insert_new_city(head, "Chicago");
	head = insert_new_city(head, "St. Louis");
	head = insert_new_city(head, "Dallas");
	head = insert_new_city(head, "Denver");
	head = insert_new_city(head, "Phoenix");
	head = insert_new_city(head, "Los Angeles");
	City* temp = head;
	while(temp!=NULL)
	{
		temp = temp->next;
	}
	tail = temp;
	printNetwork();
}

/*
* Write function name: transmitMsg;
*Purpose: to transmit the message between all cities in network word by word
*@param filename - to read word from the file and store in struct of cityName
* @return - none
*/
void CommunicationNetwork::transmitMsg(char * filename) //this is like a string
{
	string word;
	ifstream inputFile;
	inputFile.open(filename); //open the file
	if(head == NULL){
        cout<<"Empty list"<<endl;
        return;
    }
    //Reads message word by word and prints the word received
    while(inputFile >> word){ 
        City *current = head;
        while(current != NULL){
            current->message = word; //add word into current message
            cout<<current->cityName<<" received "<<current->message<<endl;
            current->message = "";	//set current message to empty string
            if(current->next == NULL){//Loop to display message back to head
                while(current->previous != NULL){
                    current = current->previous;
                    current->message = word;
                    cout<<current->cityName<<" received "<<current->message<<endl;
                    current->message = "";
                }
                break;
            }
            else {
            	current = current->next;
            }
        }
    }
	inputFile.close();
}

/*
* Write function name: printNetwork;
*Purpose: to print the name of each city in order to the end of list
*@param NONE
* @return - none
*/
void CommunicationNetwork::printNetwork()
{
	City *temp = head;
        cout<<"===CURRENT PATH==="<<endl;
        if(head !=NULL)
            cout<<"NULL <- ";
        while(temp != NULL){
            if(temp->next == NULL){
                cout<<temp->cityName<<" -> ";
                temp = temp->next;
            }
            else{
                cout<<temp->cityName<<" <-> ";
                temp = temp->next;
            }
        }
        cout<<"NULL"<<endl;
        cout<<"=================="<<endl;
}


/*
* Write function name: deleteCity;
*Purpose: to find the city in the network where city name matches removeCity
*@param cityname - city that want to delete
* @return - none
*/
void CommunicationNetwork::deleteCity(string removeCity) 
{
	
	City* deleteCity = NULL;
	City* temp = head;
	City* curr = head;
	while(curr !=NULL && curr->cityName != removeCity){
		temp = curr;
		curr = curr->next;
	}
	if(curr == NULL){
		cout<< removeCity << " not found\n";
		delete deleteCity;
	}
	else
	{
		deleteCity = curr;
		curr = curr->next;
		temp->next = curr;
		if(deleteCity ==head)
		{
			head = head->next;
			temp = NULL;
		}
		delete deleteCity;
	}

}

/*
* Write function name: deleteNetwork;
*Purpose: delete all cities in the network, starting at the head city
*@param NONE
* @return - none
*/

void CommunicationNetwork::deleteNetwork()
{
  City* temp = head;
  City* newTemp = new City;
  while(temp!=NULL)
  {
  	newTemp = temp->next;
  	cout<<"deleting "<<temp->cityName<<endl;
  	delete temp;
  	temp = newTemp;
  }
  head =NULL;
  delete temp;
}



















