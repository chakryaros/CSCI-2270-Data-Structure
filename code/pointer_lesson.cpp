#include <iostream>

using namespace std;

int main()
{
	int x = 4;
	int *ptrx = &x;
	cout<<"X:\t "<< x << "\n";
	cout<<"&x:\t "<<&x<< "\n";

	cout<<"\n";
	int intB = 50;
	int *ptrB = &intB;
	cout <<"Address of intB: "<< &intB<<endl;
	cout<<"Address of pointed to by ptrB: "<<ptrB<<endl;

	cout<<"\n";
	cout<<"Value of variable pointed to by ptrB: "<<*ptrB<<endl;
	cout<<"Value of intB: "<<intB<<endl;

	cout<<"\n";
	intB = intB + 10;
	cout<<"Now the value of *ptrB is "<<*ptrB<<endl;
	cout<<"The value of intB is "<< intB <<endl;

	int y =5;
	int *mPointer = &y;
	
	// Write C++ code that creates an integer variable called answer, 
	//  dereferences a given pointer mPointer, 
	//  and places that value into the variable answer. 
	//  The pointer mPointer will have been declared 
	//  and set to point to a value before your code runs.

	int answer = *mPointer;
	cout <<" the value of anser is: "<<answer<<endl;

	// Write C++ code that creates a float pointer aPointer 
	// to a given variable x by referencing the memory address 
	// of the variable x. The variable x has been declared 
	// and initialized before your code runs. 
	float x1 = 5.2;
	float *aPointer = &x1;
	cout <<" a value of aPointer: "<<*aPointer<<endl;
}