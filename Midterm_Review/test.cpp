#include <iostream>

using namespace std;

void myFunction(int *c)
{
	*c =10;
	cout<<*c<<endl;
}
int *func2(int *z){
	int *a = new int;
	*a = *z + 5;
	return a;
}

int main()
{
	int *a = new int;
	int b =5;
	int *a2 = &b;
	myFunction(&b);

	int b1 = 5;
	int *a1;
	a1 = &b1;
	int *c = func2(a1);
	cout<<*c<<endl;
}