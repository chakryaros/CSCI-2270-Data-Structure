//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 7/28/2018
//FinalProject Part 1


#include "GraphPartI.h"
#include <vector>
#include<iostream>
using namespace std;


// Graph::Graph(){};  // Already implemented
// Graph::~Graph(){}; // Already implemented
void Graph::addEdge(std::string v1, std::string v2, int weight)
{
	for(int i=0; i<vertices.size(); i++)
	{
		if(vertices[i].name == v1)
		{
			//cout << vertices[i].name << endl;
			for(int j=0; j< vertices.size(); j ++)
			{
				if((vertices[j].name == v2) && (i!=j))
				{
					adjVertex av;
					av.v = &vertices[j];
					av.weight = weight;
					vertices[i].adj.push_back(av);


					// adjVertex addadj1;
					// addadj1.v = &vertices[i];
					// addadj1.weight = weight;
					// vertices[j].adj.push_back(addadj1);

				}
			}
		}
	}
}

/*
* Write function name: addVertex;
*Purpose: to add the cityname into the vertices vector
*@param string name for the city
* @return - none
*/
void Graph::addVertex(std::string name)
{
	for(int i=0; i<vertices.size(); i++)
	{
		if(name ==vertices[i].name)
		{
			cout<<"Already there"<<endl;
			return;
		}
	}
	vertex v;
	v.name = name;
	vertices.push_back(v);
}
/*
* Write function name: isAdjacent;
*Purpose: to find adjacent in the vertices
*@param string v1 for city in vertices, and v2 in adjacent
* @return - true if found
*/
int Graph::isAdjacent(std::string v1, std::string v2)
{
	bool found = false;
	for(int i=0; i<vertices.size(); i++)
	{
		if(vertices[i].name == v1)
		{
			for(int j=0; j<vertices[i].adj.size(); j++)
			{
				//cout << vertices[i].adj[j].v->name << endl;
				//cout << v2 << endl;
				if(vertices[i].adj[j].v->name == v2)
				{
					found = true;
					break;
				}
			}
		}
		
	}
	if(found==true)
	{
		cout<<"True"<<endl;
	}
	else
	{
		cout<<"False"<<endl;
	}
	return 1;
}

/*
* Write function name: displayEdges;
*Purpose: to print the the city in vertice and adjacent
*@param none
* @return - none
*/
void Graph::displayEdges(){

	for(int i=0; i<vertices.size(); i++)
	{
		cout<<vertices[i].name <<"-->";
		for(int j=0; j<vertices[i].adj.size(); j++)
		{
			cout<<vertices[i].adj[j].v->name;
			if( j!=vertices[i].adj.size()-1)
			{
				cout<<"***";
			}
		}
		cout<<endl;
	}
}






















