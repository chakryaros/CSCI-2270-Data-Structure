#include <cstdlib>
#include "LinkList.h"
#include "LinkList.cpp"
using namespace std;

int main(int agrc, char** argv){
	LinkList Yanit;
	Yanit.AddNode(3);
	Yanit.AddNode(5);
	Yanit.AddNode(7);
	Yanit.PrintList();
	Yanit.DeleteNode(3);
	Yanit.DeleteNode(8);
	Yanit.AddNode(8);
	Yanit.PrintList();
	return 0;

}