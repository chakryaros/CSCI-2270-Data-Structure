//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 7/08/2018
//Assignment4

#include <fstream>
#include <sstream>
#include "MovieTree.hpp"

#include <iostream>

using namespace std;

void menu()
{
	cout<<"=======Main Menu======\n";
	cout<<"1. Find a movie\n";
	cout<<"2. Rent a movie\n";
	cout<<"3. Print the inventory\n";
	cout<<"4. Delete a movie\n";
	cout<<"5. Count the movies\n";
	cout<<"6. Quit\n";
	
}
int main(int argc, char* argv[])
{
	//declare new MovieTree
	MovieTree movieTree;

	//open the file
	ifstream inputFile;
	inputFile.open(argv[1]);
	if(inputFile.fail())
	{
		cout<<"File can not open\n";
	}
	string line, rankString, yearString, quantitystring;
	int rank =0;
	int year =0;
	int quantity =0;
	string title="";
	while(getline(inputFile, line))
	{
		stringstream ss(line);
		getline(ss, rankString, ',');
		rank = stoi(rankString);
		getline(ss, title, ',');
		getline(ss, yearString, ',');
		year= stoi(yearString);
		getline(ss, quantitystring, ',');
		quantity = stoi(quantitystring);
		
		//add movie into movieTree
		movieTree.addMovieNode(rank, title, year, quantity); 
	} 
	char choice;
	while(choice != '6')  //loop for user's choice
	{
		menu();	//call menu function
		cin>>choice;	//ask user to enter their choice
		if(choice=='1')		//find movie
		{
			string name;
			cout<<"Enter a movie name:";
			cin>>ws;
			getline(cin, name);
			movieTree.findMovie(name); //find a movie
		}
		else if(choice =='2')	//to rent a movie
		{
			string name;
			cout<<"Enter a movie name:";
			cin>>ws;
			getline(cin, name);
			movieTree.rentMovie(name);
		}
		else if(choice =='3') // to print list of movie 
		{
			movieTree.printMovieInventory();
		}
		else if(choice =='4') { // to delete movie as user's choice
			
			string name;
			cout<<"Enter title:";
			cin>>ws;
			getline(cin, name);
			movieTree.deleteMovieNode(name);
		}
		else if(choice =='5') //to count the movie
		{
			cout<<"Tree contains: "<<movieTree.countMovieNodes()<<" movies" <<endl;
		}
		else if(choice =='6') //to quit and delete all movie
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
	inputFile.close();
	return 0;
}



