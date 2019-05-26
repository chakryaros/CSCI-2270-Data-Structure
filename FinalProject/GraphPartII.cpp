//Author: Chakrya Ros
//Instructor:Christopher Godley
//TA: Shudong Hao
//Date: 7/28/2018
//FinalProject Part 2


#include "GraphPartII.hpp"
#include<stack>
#include<queue>
#include <vector>
#include<iostream>
#include <queue>
using namespace std;


Graph::Graph(){

}  
Graph::~Graph(){

}
void Graph::addEdge(std::string v1, std::string v2, int weight)
{
	for(int i=0; i<vertices.size(); i++)
	{
		//search city name in the vertices vector
		if(vertices[i].name == v1)
		{
			//loop to search city name in adjacent
			for(int j=0; j< vertices.size(); j ++)
			{
				//if the city name found and not the same in vertices
				if((vertices[j].name == v2) && (i!=j))
				{
					//create new adjVertex, add vertices i and weight to pointer
					adjVertex av;
					av.v = &vertices[j];
					av.weight = weight;
					//av.v->visited = false;
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
*Purpose: to add the city name to vertices vector
*@param string for city name
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

	//create new vertex and add to vertices vector
	vertex v;
	v.name = name;
	v.districtID = -1;  	//assign the distrtictID to -1
	v.ID = vertices.size();
	v.visited = false;		//assign visited boolen to false
	vertices.push_back(v);
}

/*
* Write function name: displayEdges;
*Purpose: to print the verticse and its adjacent
*@param none
* @return - none
*/

void Graph::displayEdges(){
	//loop through the vertices list
	for(int i=0; i<vertices.size(); i++)
	{
		cout<<vertices[i].districtID<<":";
		cout<<vertices[i].name <<"-->";
		//for all adjacent
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

/*
* Write function name: assignDistricts;
*Purpose: find all vertices that connected to that vertex and
*			assigned to a district by call DFS function
*@param none
* @return - none
*/

void Graph::assignDistricts()
{
	//start disctrict at 1
	int distID = 1;

	//for each of the vertices
	for(int i=0; i<vertices.size(); i++)
	{
		//if the vertex does not assigned a district
		if(vertices[i].districtID==-1)
		{
			//call the DFSLabel function and assign each node in the graph
			DFSLabel(vertices[i].name, distID);
			distID++;
		}
	}
}
// Breadth First Search
/*
* Write function name: shortestPath;
*Purpose: to search for shortest path by use BFS
*@param string for start_City and for end_city
* @return - none
*/
void Graph::shortestPath(std::string startingCity, std::string endingCity)
{
	
	for(int i=0; i<vertices.size(); i++)
	{
		vertices[i].parent = NULL;
		vertices[i].visited = false;
	}

	vertex* startV = NULL;
	vertex* endV =NULL;
	startV = findVertex(startingCity); //Find the start city and enquence it
	endV = findVertex(endingCity);
	if(startV == NULL || endV == NULL)
	{
		cout<<"One or more cities doesn't exit\n";
		return;
	}
	if(startV->districtID != endV->districtID)
	{
		cout<<"No safe path between cities\n";
		return;
	}
	if(startV->districtID == -1 || endV->districtID == -1)
	{
		cout<<"Please identify the district before checking distances\n";
		return;
	}
	//assign startV as visited
	startV->visited = true;
	startV->unweightedDistance =0;
	startV->parent = NULL;
	queue<vertex*> q;
	q.push(startV);
	while(!q.empty())
	{
		vertex * n;
		n = q.front(); //get the next one from queue
		q.pop(); //reomve theat one from queue

		for(int i=0; i<n->adj.size(); i++)
		{
			if(n->adj[i].v->visited == false)
			{
				n->adj[i].v->visited = true;
				n->adj[i].v->parent = n;
				n->adj[i].v->unweightedDistance = n->unweightedDistance + 1;
				q.push(n->adj[i].v);
			}
		}
	}
	//print the path in order
	stack<string> reverse_path;
	vertex* curr = endV;
	while( curr !=NULL)
	{
		reverse_path.push(curr->name);
		curr = curr->parent; //assign current parent pointer to current pointer
	}
	cout<<endV->unweightedDistance;
	while(!reverse_path.empty())
	{
		cout<< ",";
		cout<<reverse_path.top();
		reverse_path.pop();
	}
	cout<<endl;
	
}
// Dijkstras to find shortest weight path
void Graph::shortestWeightedPath(std::string startingCity, std::string endingCity)
{
	for(int i=0; i<vertices.size(); i++)
	{
		vertices[i].parent = NULL;
		vertices[i].visited = false;
	}
	vertex* startV;
	vertex* endV;
	//find the start and end node
	startV = findVertex(startingCity);
	endV = findVertex(endingCity);
	if(startV == NULL || endV == NULL)
	{
		cout<<"One or more cities doesn't exit\n";
		return;
	}
	if(startV->districtID != endV->districtID)
	{
		cout<<"No safe path between cities\n";
		return;
	}
	if(startV->districtID == -1 || endV->districtID == -1)
	{
		cout<<"Please identify the district before checking distance\n";
		return;
	}

	//Mark the start as solved with distance 0
	startV->visited = true;
	startV->weightedDistance = 0;
	int minDistance;
	startV->parent = NULL;
	vector<vertex*> solved;
	solved.push_back(startV); //store list of solved vertices
	while(!endV->visited)
	{
		int minDistance = INT_MAX;
		vertex* solvedV = NULL;
		vertex* parent = NULL;
		//loop through the list of solved vertices
		for(int x =0; x<solved.size(); x++)
		{
			vertex* s = solved[x];
			for(int y=0; y < s->adj.size(); y++) //look at all adjacent
			{
			 	if(s->adj[y].v->visited==false)
				{
			 		int dist = s->weightedDistance + s->adj[y].weight;
					if(dist < minDistance)
					{
						solvedV = s->adj[y].v;
						minDistance = dist;
						parent = s;
					}
			 	}
			}
		}
		solvedV->weightedDistance = minDistance;
		solvedV->parent = parent;
		solvedV->visited = true;
		solved.push_back(solvedV);
	}

	//print the path in order

	cout<<endV->weightedDistance; //print the shortest path
	stack<string> reverse_path;
	vertex* curr = endV;		//assign ending city to curr vectex
	//loop until curr is null
	while( curr !=NULL)
	{
		reverse_path.push(curr->name);
		curr = curr->parent; //assign current parent pointer to current pointer
	}
	while(!reverse_path.empty())
	{
		cout<< ",";
		cout<<reverse_path.top();
		reverse_path.pop();
	}
	cout<<endl;

}

//Private Function
vertex * Graph::findVertex(std::string name)
{
	for(int i=0; i<vertices.size(); i++)
	{
		if(vertices[i].name==name)
		{
			return &vertices[i];
		}
	}
	return NULL;
}
/*
    Call this from within assignDistricts to label the districts.
    This method should implement a depth first search from the 
    startingCity and assign all cities encountered the distID value.
*/
void Graph::DFSLabel(std::string startingCity, int distID)
{
	vertex* v;
	stack<vertex*> stack;
	//stack<vertex> stack;
	v = findVertex(startingCity);
	v->visited = true;
	v->districtID = distID;
	stack.push(v);
	while(!stack.empty())
	{
		//pop  a vertex from stack
		vertex *v1;
		v1 = stack.top();
		stack.pop();
		for(int x =0; x<v1->adj.size(); x++)
		{
			if(v1->adj[x].v->visited==false)
			{
				v1->adj[x].v->visited=true;
				v1->adj[x].v->districtID = distID;
				stack.push(v1->adj[x].v);
			}
		}
	}
}























