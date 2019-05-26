#include "Graph.h"
#include <queue>
#include <stack>
//#include <vector>
//#include <iostream>
using namespace std;


Graph::Graph(){};
Graph::~Graph() {};
void Graph::addEdge(std::string v1, std::string v2, int weight)
{
	for(int i = 0; i< vertices.size(); i++)
	{
		if(vertices[i].name == v1)
		{
			for(int j= 0; j < vertices.size(); j++)
			{
				if(vertices[j].name == v2 && i != j)
				{
					adjVertex av;
					av.v = &vertices[j];
					av.weight = weight;
					vertices[i].adj.push_back(av);
				}
			}
		}
	}
}
void Graph::addVertex(std::string name)
{
	for(int i=0; i< vertices.size(); i++)
	{
		if( name==vertices[i].name) {
			cout<< "Already there" <<endl;
			return;
		}
	}

	vertex v;
	v.name = name;
	vertices.push_back(v);
}
void Graph::displayEdges()
{
	for(int i=0; i<vertices.size(); i++)
	{
		cout<<vertices[i].name <<"-->";
		for(int j=0; j<vertices[i].adj.size(); j++)
		{
			cout<<vertices[i].adj[j].v->name<<" ";
			if(j != vertices[i].adj.size()-1)
			{
				cout<<"***";
			}
		}
		cout<<endl;
	}
}

void Graph::BFS_path(string src, string dist)
{
	//Reset
	for(int i=0; i < vertices.size(); i++)
	{
		vertices[i].parent = NULL;
		vertices[i].visited = false;
	}


	vertex* start = NULL;
	vertex* end = NULL;
	for(int i=0; i< veritces.size(); i++)
	{
		if(vertices[i].name == src)
		{
			start = &vertices[i];
		}
		else if(vertices[i].name == dist)
		{
			end = &vertices[i];
		}
	}

	if(start == NULL || end == NULL)
	{
		cout<<"Not in the graph"<<endl;
		return;
	}

	//Traversal
	start->visited = true;
	start->parent = NULL;
	//if we use DFS, change to stack
	queue<vertex*> q
	q.push(start);

	while(!q.empty())
	{
		vertex* curr = q.front();
		q.pop();

		for(int i=0; i< curr->adj.size(); i++)
		{
			if(curr->adj[i].v->visited == false)
			{
				curr->adj[i].v->visited = true;
				curr->adj[i].v->parent = curr;
				q.push(curr->adj[i].v);
			}
		}
	}

	stack<string> reverse_path;
	vertex* curr = end;
	while( curr != NULL)
	{
		reverse_path.push(curr->name);
		curr = curr->parent;
	}

	while(!reverse_path.empty())
	{
		cout<< reverse_path.top() << "-->";
		reverse_path_path.pop();
	}

}

// vertex* serarch(string name)
// {
// 	for(int i=0; i<vertices.size(); i++)
// 	{
// 		if(vertices[i].name == name)
// 			return vertices[i];
// 	}
// 	return NULL;
// }








