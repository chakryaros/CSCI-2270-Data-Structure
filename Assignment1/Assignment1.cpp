// Author: Chakrya Ros
// Instructor:Christopher Godley
// TA: Shudong Hao
// Assignment1


#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
#include <iomanip>
using namespace std;

//declare the object of garageSale
struct garageSale 
{
	string items;
	bool sale;
	int price;
};

int main(int argc, char* argv[])
{
	garageSale array[100];			//declare the array of garageSale object
	//garageSale newSale = {"", -1, 0};				
	//fstream Infile("garageSale.txt");		//open the file
	fstream Infile(argv[1]);
	if(Infile.fail())				//check if the file is open or not
	{
		cout<<"File can not open"<<endl;
	}
	string line;	//declare varible of string
	int index=0;
	string item1, tempString;
	string myString;
	bool sale1;
	int price1;
	int numberSold=0;
	while(getline(Infile, line))	//read the file line by line
	{
		stringstream ss(line);		//read each line
		getline(ss, item1, ',');
		getline(ss, tempString, ',');
		if(tempString==" wanted")	
		{
			sale1=true;
		}
		else
		{
			sale1=false;
		}
		getline(ss, myString, ',');
		price1 = stoi(myString);
		garageSale newSale = {item1, sale1, price1};			//assign the item, sale and price into newSale
		array[index]=newSale;		//add newSale into the array of garageSale
		index++;	//increment
		for(int i=0; i<index-1; i++) //use for loop to search for match or not
		{
			//if items in array found in newSale and for sale/wanted not found in newSale
			if(array[i].items==newSale.items && array[i].sale!=newSale.sale)
			{
				if(array[i].sale==0) //for sale
				{
					if(array[i].price <= newSale.price) //if the price in array is less or equal to the newSale
														//it match, so remove the item from array
					{
						cout<< array[i].items << " " << array[i].price<<endl;
						cout<<endl;
						for(int x=i; x<index; x++) //use for loop to delete items that match
						{
							array[x]=array[x+1]; //set array postion x equal to position x + 1
						}
						index= index-2;
						numberSold++;
						break;
					}
				}
				if(array[i].sale==1) //wanted
				{
					if(array[i].price >= newSale.price) //if the price in array is greater or equal to newSale
														//match is found
					{
						cout << newSale.items<< " " << newSale.price<<endl;
						cout<<endl;
						for(int x=i; x<index; x++)	//use for loop to delete items that match
						{
							array[x]=array[x+1];
						}
						index = index-2;			//set array postion x equal to position x + 1
						numberSold++;
						break;
					}
				}
			}
		}
	}
	cout<<numberSold<<endl; //print out the number of sold
	cout<<endl;
	int count=0;
	//print out the item that left in array of garageSale
	for(int i=0; i<index; i++)
	{
		if(array[i].sale==0) //if array at index i, equal zero, print the items for sale
		{
			cout<<array[i].items<<", for sale, "<<array[i].price<<endl;
			cout<<endl;
			count++;
		}
		else if(array[i].sale==1) //if array at index i, equal one, print the items wanted
		{
			cout<<array[i].items<<", wanted, "<<array[i].price<<endl;
			cout<<endl;
			count++;
		}
	}
	cout<<count<<endl; //print out the number of items in array of garageSale
	Infile.close();
	return 0;
}