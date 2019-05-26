#include <iostream>

using namespace std;

void foo(int* a){
	int*b = new int;
	cout<<"Address of b = "<<b << endl;
	a =b;
}

int main()
{
	int* a = new int;
	cout<<"Address of a = "<< a <<endl;

	foo(a);
	cout<<" After function = " <<a<<endl;
	return 0;
}