//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 6/29/2018
//Assignment3


#include <iostream>
#include "CommunicationNetwork.h"

using namespace  std;

void menu()
{
	cout<<"=======Main Menu======\n";
	cout<<"1. Build Network\n";
	cout<<"2. Print Network Path\n";
	cout<<"3. Transmit Message Coast-To-Coast-To-Coast\n";
	cout<<"4. Add City\n";
	cout<<"5. Delete City\n";
	cout<<"6. Clear Network\n";
	cout<<"7. Quit\n";
	
}

int main(int argc, char* argv[])
{
	
	CommunicationNetwork network; //declare the object
	char choice;
	while(choice != '7')  //loop for user's choice
	{
		menu();	//call menu function
		cin>>choice;	//ask user to enter their choice
		if(choice=='1')		//if choice is one, call function build network of linked list
		{

			network.buildNetwork();
		}
		else if(choice =='2')	//if choice is two, call function to print the linked list of city
		{
			network.printNetwork();
		}
		else if(choice =='3') // if choice is three, call function transmiMsg to read file and transmit word from one city to another
		{
			network.transmitMsg(argv[1]);
		}
		else if(choice =='4') // if choice is four, add new city to head/middle/tail as user's choice
		{
			cout<<"Enter a city name: " <<endl;
			string name;
			cin>>ws;
			getline(cin, name);

			cout<<"Enter a previous city name: "<<endl;
			string prevCity;
			getline(cin, prevCity);
			network.addCity(name, prevCity);
		}
		else if(choice =='5') //if choice is five, delete city as user's choice
		{
			cout<<"Enter a city name: " <<endl;
			string name;
			cin>>ws;
			getline(cin, name);
			network.deleteCity(name);
		}
		else if(choice =='6') // if chice is six, delete the network
		{
			network.deleteNetwork();
		}
		else if(choice =='7')
		{
			cout<<"Goodbye!\n";
		}
		else
		{
			cout<<"Please enter the choice number again: ";
			cin>>choice;
			cin.ignore();
		}
	}
	return 0;
}














