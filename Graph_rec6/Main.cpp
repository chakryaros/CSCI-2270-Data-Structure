#include "Graph.h"
//#include <iostream>
#include <sstream>
#include <fstream>
//#include <vector>
using namespace std;



int main(int argc, char* argv[])
{
	ifstream myFile(argv[1]);
	string line;
	getline(myFile, line);
	cout<<line<<endl;

	string cityname;
	stringstream sp(line);
	getline(sp, cityname, ' '); //read cities
	Graph g;
	while(getline(sp, cityname, ' ')) {
		//cout<<cityname<<endl;
		g.addVertex(cityname);
	}
	g.displayEdges();

	// for(int i=0; i<g.vertices.size(); i++)
	// {
	// 	cout<<g.vertices[i].name<<endl;
	// }
	return 0;
}