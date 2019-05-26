#include "MST.h"	
#include <vector>
#include <queue>
#include <iostream>
#include <sstream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

MST::MST()
{

}

MST::~MST()
{
	//dtor
}

void MST::addEdge(std::string v1, std::string v2, int weight)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].name == v1)
		{
			for (int j = 0; j < vertices.size(); j++)
			{
				if (vertices[j].name == v2 && i != j)
				{
					adjVertex av;
					av.v = &vertices[j];
					av.weight = weight;
					//cout << vertices[i].district << " -- " << vertices[j].district << " : " << weight << endl;
					vertices[i].adj.push_back(av);
					/*
					//another vertex for edge in other direction
					adjVertex av2;
					av2.v = &vertices[i];
					av2.weight = weight;
					vertices[j].adj.push_back(av2);
					*/
				}
			}
		}
	}
}

void MST::addVertex(std::string name)
{
	bool found = false;
	for (int i = 0; i < vertices.size(); i++)
	{
		if (vertices[i].name == name)
		{
			found = true;
			cout << vertices[i].name << " found." << endl;
		}
	}
	if (found == false)
	{
		vertex v;
		v.name = name;
		v.visited = false;
		v.distance = 0;
		v.district = districtNum;
		vertices.push_back(v);
		districtNum++;
	}
}

void MST::displayEdges()
{
	//loop through all vertices and adjacent vertices
	for (int i = 0; i < vertices.size(); i++)
	{
		cout << vertices[i].district << ":" << vertices[i].name << "-->";
		for (int j = 0; j < vertices[i].adj.size(); j++)
		{
			cout << vertices[i].adj[j].v->name;
			if (j != vertices[i].adj.size() - 1)
				cout << "***";
		}
		cout << endl;
	}
}

//--------------------------------------------------------------------------------------
struct Graph* MST::createGraph(int V, int E) //create a graph with V vertices and E edges
{
	struct Graph* graph = new Graph;
	graph->V = V; //the number of vertices
	graph->E = E; //the number of edges
	graph->edge = new Edge[E]; //allocate Edge structure array according to the number of edges

	return graph;
}
int MST::find(struct subset subsets[], int i) //utility function to find set of an element i
{
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);

	return subsets[i].parent;
}
void MST::Union(struct subset subsets[], int x, int y) //function that does union of two sets of x and y
{
	int xroot = find(subsets, x);
	int yroot = find(subsets, y);

	if (subsets[xroot].priority < subsets[yroot].priority)
		subsets[xroot].parent = yroot;
	else if (subsets[xroot].priority > subsets[yroot].priority)
		subsets[yroot].parent = xroot;
	else
	{
		subsets[yroot].parent = xroot;
		subsets[xroot].priority++;
	}
}
int compar(const void* a, const void* b) //Pointer to a function that compares two elements.
 //This function is called repeatedly by qsort to compare two elements
{
	const struct Edge* a1 = (const struct Edge*) a;
	const struct Edge* b1 = (const struct Edge*) b;
	return a1->weight > b1->weight;
}
void MST::KruskalMST()
{
	//------------------------------------------------------------------------------
	//To create a graph, transfer all cities' data from vertices to the graph
	struct Edge temp[50];
	for (int x = 0; x < 50; x++) 
	{
		temp[x].srcDistrict = -1;
		temp[x].destDistrict = -1;
		temp[x].weight = -1;
	}
	bool check = false;
	int edgeCount = 0; //count the number of edges

	for (int i = 0; i < vertices.size(); i++) //loop through vertices to extract all edges from vertices
	{
		for (int j = 0; j < vertices[i].adj.size(); j++)
		{
			if (vertices[i].adj[j].weight != 0)
			{
				for (int k = 0; k < 50; k++) //check if edge is already stored in temp
				{
					if (vertices[i].district == temp[k].destDistrict && vertices[i].adj[j].v->district == temp[k].srcDistrict)
						check = true;
				}
				if (!check)
				{
					//cout << vertices[i].district << " -- " << vertices[i].adj[j].v->district << " : " << vertices[i].adj[j].weight << endl;
					temp[edgeCount].srcDistrict = vertices[i].district;
					temp[edgeCount].srcName = vertices[i].name;
					temp[edgeCount].destDistrict = vertices[i].adj[j].v->district;
					temp[edgeCount].destName = vertices[i].adj[j].v->name;
					temp[edgeCount].weight = vertices[i].adj[j].weight;
					edgeCount++;
				}
				check = false;
			}
		}
	} //transferred all cities' data from vertices to the graph

	//------------------------------------------------------------------------------
	//create a graph
	int V = vertices.size(); // number of vertices in graph
	int E = edgeCount; // number of edges in graph
	struct Graph* graph = createGraph(V, E); //create a graph
	//cout << edgeCount << endl;

	cout << "Following are the edges in the graph" << endl;
	for (int u = 0; u < E; u++) //store all edge information
	{
		cout << "(" << temp[u].srcDistrict << ")" << temp[u].srcName 
			<< " <---> " << "(" << temp[u].destDistrict << ")" << temp[u].destName << "	" << temp[u].weight << endl;
		graph->edge[u].srcDistrict = temp[u].srcDistrict;
		graph->edge[u].srcName = temp[u].srcName;
		graph->edge[u].destDistrict = temp[u].destDistrict;
		graph->edge[u].destName = temp[u].destName;
		graph->edge[u].weight = temp[u].weight;
	}

	KruskalMST(graph); // sending graph, call Kruskal Algorithm to find out the minimum spanning tree

	/*
	 // A following diagram below is a graph created
			10       16
		0--------1--------4
		| \	     |
	   6|  5\    |15
		|     \  |
		2--------3
			4	 
	*/
}
void MST::KruskalMST(struct Graph* graph) //main function to construct MST using Kruskal's algorithm
{
	int V = graph->V;
	result = new Edge[V];
	int e = 0;
	int i = 0;

	qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compar); //qsort(base, num, size, compar);
	//base: Pointer to the first object of the array to be sorted
	//num: Number of elements in the array pointed to by base
	//size: Size in bytes of each element in the array

	struct subset *subsets = new subset[V];
	for (int v = 0; v < V; ++v)
	{
		subsets[v].parent = v;
		subsets[v].priority = 0;
	}

	while (e < V - 1)
	{
		struct Edge next_edge = graph->edge[i++];

		int x = find(subsets, next_edge.srcDistrict);
		int y = find(subsets, next_edge.destDistrict);

		if (x != y)
		{
			result[e++] = next_edge;
			Union(subsets, x, y);
		}
	}

	//------------------------------------------------------------------------------
	// print the contents of result[] to display the built MST
	cout << "\nFollowing are the edges in the constructed MST" << endl;
	for (i = 0; i < e; ++i)
		//printf("%d -- %d == %d\n", result[i].srcDistrict, result[i].destDistrict,result[i].weight);
		cout << "(" << result[i].srcDistrict << ")" << result[i].srcName << " <---> "
			<<  "(" <<result[i].destDistrict << ")" << result[i].destName <<  "	" << result[i].weight  << endl;
	cout << endl;
	return;
}
vertex* MST::findVertex(std::string name)
{
	for (int i = 0; i < 10; i++)
	{
		if (vertices[i].name == name)
			return &vertices[i];
	}
	return NULL;

}