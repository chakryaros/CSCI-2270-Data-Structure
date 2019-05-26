//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 7/28/2018
//FinalProject Part 2

#include<fstream>
#include<sstream>
#include"Graph.hpp"
#include<iostream>
using namespace std;



void menu()
{
	cout<<"=======Main Menu======\n";
	cout<<"1. Print vertices\n";
	cout<<"2. Find disticts\n";
	cout<<"3. Find shortest path\n";
	cout<<"4. Find shortest weighted path\n";
	cout<<"5. Quit\n";
	
}
int main(int argc, char* argv[])
{
	ifstream myFile;
	myFile.open(argv[1]);
	if(myFile.fail())
	{
		cout<<"File can not open\n";
	}

	vector<string> cities;
	string cityname;
	string line;

	//read the first line
	getline(myFile, line);
	stringstream sp(line);
	getline(sp, cityname, ',');
	Graph g;
	while(getline(sp, cityname, ','))
	{
		g.addVertex(cityname);
		cities.push_back(cityname);
	}
	int i=0;
	string city;

	//read the whole text file

	while (getline(myFile, line)) {
		stringstream ss(line);
		i = -1;
		while(getline(ss, city, ','))
		{
			if(i == -1)
			{
				cityname = city;
			}
			else
			{
				if(city != "-1" && city !="0")
				{
					int weight = stoi(city);
					//cout<<cityname<<endl;
					g.addEdge(cityname, cities[i], weight);
				}
			}
			i++;
		}

	}

	char choice;
	while(choice !='5')
	{
		menu();
		cin>>choice;
		if(choice=='1')
		{
			g.displayEdges();
		}
		else if(choice=='2')
		{
			g.assignDistricts();
		}
		else if(choice=='3')
		{
			string startCity, EndCity;
			cout<<"Enter a starting city:\n";
			cin>>ws;
			getline(cin, startCity);
			cout<<"Enter an ending city:\n";
			getline(cin, EndCity);
			g.shortestPath(startCity, EndCity);	
		}
		else if(choice=='4')
		{
			string startCity, EndCity;
			cout<<"Enter a starting city:\n";
			cin>>ws;
			getline(cin, startCity);
			cout<<"Enter an ending city:\n";
			getline(cin, EndCity);
			g.shortestWeightedPath(startCity, EndCity);	
		}
		else if(choice=='5')
		{
			cout<<"Goodbye!\n";	
		}
	}
	myFile.close();
	return 0;

}





